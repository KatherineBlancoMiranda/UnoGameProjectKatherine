#include "classmenu.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>


Menu::Menu()
{
	show = false;

}

void Menu::setMenuTexture(sf::Texture& menuTexture)
{
	menu.setTexture(menuTexture);
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	if (!show) {
		return;
	}

	window.draw(menu);
}

void Menu::showMenu()
{
	menu.setScale(1, 1);
	menu.setTextureRect(sf::IntRect(0, 0, 610, 449));

	show = true;

}

void Menu::showWinner(float yPosition)
{
	menu.setScale(0.5, 0.5);

	menu.setTextureRect(sf::IntRect(612, 0, 610, 449));

	menu.setPosition(0, yPosition);

	show = true;
}

void Menu::hideBox()
{
	show = false;
}

bool Menu::boxIsOpen()
{
	return show;
}
