#pragma once

class State
{

private:


protected:
	 //V�ltoz�k:

	//A p�lyasz�lek: Fels�,als�,bal,jobb mindegyik egy t�glalap alakazat.

	sf::RectangleShape UpperRect;
	sf::RectangleShape DownRect;
	sf::RectangleShape LeftRect;
	sf::RectangleShape RightRect;

	sf::RenderWindow* window;

	//std::vector<sf::Texture> textures;
	std::vector<sf::RectangleShape> borders;

	bool quit;
	bool play;
protected:

	sf::Font font;

	void InitBorders();
public:

	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void checkForQuit() = 0;

	virtual void endState() = 0;

	virtual void updateKeybinds() = 0;//const float& dt
	virtual void update(const float& dt) = 0;
	virtual void render() = 0;//sf::RenderWindow* window = nullptr

	const bool& getQuit() const { return this->quit; };
	const bool& getPlay() const { return this->play; };


};
