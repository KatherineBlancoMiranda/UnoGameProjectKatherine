#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>

class Menu {

public:

	Menu();

	void setMenuTexture(sf::Texture& menuTexture);

	void drawMenu(sf:: RenderWindow& window);

	void showMenu();

	void showWinner(float yPosition);

	void hideBox();

	bool boxIsOpen();

private:

	sf::Sprite menu;
	bool show;

};