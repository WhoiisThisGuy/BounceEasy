#include "pch.h"
#include "Game.h"


Game::Game()

	:GameOver(false)

{

	this->initWindow();
	this->initStates();
	this->ScreenHeight = window->getSize().y;
	this->ScreenWidth = window->getSize().x;
}

//Initializer
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,700),"PinFasterBall");
	window->setFramerateLimit(200);
}

void Game::initStates()
{

	this->states.push(new MenuState(this->window));
	
}

//A game destruktora, töröljük a window-ot mivel new-al allokáltuk a heap-en, valamint az összes statet amíg nem empty
//a delete-el még megmaradna a stacken az iterátor de mivel már töröltük az ott lévõ adatot pop-olni is kell, hogy ne
//hogy ne maradjon üres rész.

Game::~Game() {

	delete this->window;
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::endApplication()
{

}

void Game::updateDt()
{
	//Update: mennyi idõ alatt frissít egy képkockát így más teljesitményû pc-n is ugyanannyi idõvel mozog a unit
	this->dt = this->deltaClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{   //minden eventet figyel, ha az event a closed volt akkor a bezárás.
	while (this->window->pollEvent(this->sfEvent))
	{

		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

//State machine megoldás-t bevezetni mindenképpen a stackes megoldás helyett.
void Game::update()
{
	this->updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (dynamic_cast<GameState*>(this->states.top()) && (this->states.top()->getQuit() || this->states.top()->getPlay())) {

			if (this->states.top()->getQuit())
				{
					delete this->states.top();
					this->states.pop();
					this->states.push(new MenuState(this->window));
				}
			else if (this->states.top()->getPlay()) {

				delete this->states.top();
				this->states.pop();
				this->states.push(new GameState(this->window));

			}
		}

		else if (dynamic_cast<MenuState*>(this->states.top()) && (this->states.top()->getQuit() || this->states.top()->getPlay())) {
			//this->states.top()->endState(); //ez az endState, esetleg ha valamit végre akarok még hajtani
			//Ezt azért itt delete és nem a destruktorban mert ha még le akarok játszani valami end animationt akkor itt meglehet tenni.
			
			if(this->states.top()->getQuit())
				while (!this->states.empty()) {
					delete this->states.top();
					this->states.pop();
				}
			else if (this->states.top()->getPlay()) {
			
				delete this->states.top();
				this->states.pop();
				this->states.push(new GameState(this->window));
			}
		}
		
	}
	else
	{
		this->endApplication();
		this->window->close();

	}
}

//Clear

//törlünk mindent ami aktuálisan a képernyõn van
//a stack (ami a pályákat tárolja, menüket) legtetején lévõ state kirajzolását hivjuk meg.
//végül a megjelenítés

void Game::render()
{

	this->window->clear();

	//Render Items

	if (!this->states.empty()) //GameOvert a GameState-ben állítom be és a Collider dönt mi lesz benne
		this->states.top()->render();

	this->window->display();

}

//updateDt: a deltatime clockot indítja újra. A deltatime a while minden újabb ciklusába frissül
//			így megkapjuk mennyi idõ telt el két frissítés között, deltatimeal szorozva mozgatjuk majd a karatereket alakzatokat
//          ez azért jobb mint a frame rate mert gyengébb gépen amelyik kevesebb framet tud megjeleníteni lasabb lenne a játék
//          de a deltatime nem függ a frame rate-tõl
//update:   ez a függvény végzi a változtatásokat, mozgatás, eventek, esetleg animációknál következõ képkocka betöltése.
//render:   az updatelt állapot kirajzolása
void Game::run()
{

	while (this->window->isOpen())
	{
		
		
		this->updateDt();
		this->update();
		this->render();
		
	}

}
