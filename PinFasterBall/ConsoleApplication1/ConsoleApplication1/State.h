#pragma once

class State
{

private:


protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

	bool quit;

public:

	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void checkForQuit();

	virtual void endState() = 0;

	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderWindow* window = nullptr) = 0;//

	const bool& getQuit() const;

};
