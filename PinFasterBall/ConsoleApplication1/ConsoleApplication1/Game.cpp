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

//A game destruktora, t�r�lj�k a window-ot mivel new-al allok�ltuk a heap-en, valamint az �sszes statet am�g nem empty
//a delete-el m�g megmaradna a stacken az iter�tor de mivel m�r t�r�lt�k az ott l�v� adatot pop-olni is kell, hogy ne
//hogy ne maradjon �res r�sz.

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
	//Update: mennyi id� alatt friss�t egy k�pkock�t �gy m�s teljesitm�ny� pc-n is ugyanannyi id�vel mozog a unit
	this->dt = this->deltaClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{   //minden eventet figyel, ha az event a closed volt akkor a bez�r�s.
	while (this->window->pollEvent(this->sfEvent))
	{

		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

//State machine megold�s-t bevezetni mindenk�ppen a stackes megold�s helyett.
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
			//this->states.top()->endState(); //ez az endState, esetleg ha valamit v�gre akarok m�g hajtani
			//Ezt az�rt itt delete �s nem a destruktorban mert ha m�g le akarok j�tszani valami end animationt akkor itt meglehet tenni.
			
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

//t�rl�nk mindent ami aktu�lisan a k�perny�n van
//a stack (ami a p�ly�kat t�rolja, men�ket) legtetej�n l�v� state kirajzol�s�t hivjuk meg.
//v�g�l a megjelen�t�s

void Game::render()
{

	this->window->clear();

	//Render Items

	if (!this->states.empty()) //GameOvert a GameState-ben �ll�tom be �s a Collider d�nt mi lesz benne
		this->states.top()->render();

	this->window->display();

}

//updateDt: a deltatime clockot ind�tja �jra. A deltatime a while minden �jabb ciklus�ba friss�l
//			�gy megkapjuk mennyi id� telt el k�t friss�t�s k�z�tt, deltatimeal szorozva mozgatjuk majd a karatereket alakzatokat
//          ez az�rt jobb mint a frame rate mert gyeng�bb g�pen amelyik kevesebb framet tud megjelen�teni lasabb lenne a j�t�k
//          de a deltatime nem f�gg a frame rate-t�l
//update:   ez a f�ggv�ny v�gzi a v�ltoztat�sokat, mozgat�s, eventek, esetleg anim�ci�kn�l k�vetkez� k�pkocka bet�lt�se.
//render:   az updatelt �llapot kirajzol�sa
void Game::run()
{

	while (this->window->isOpen())
	{
		
		
		this->updateDt();
		this->update();
		this->render();
		
	}

}
