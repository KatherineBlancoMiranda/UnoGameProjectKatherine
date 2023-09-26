#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;

struct card {

	int type, color;
	bool effect = true;

};

class Player {

public:

	Player();

	void generateCards();

	void shuffleCards();

	void addCard(card aCard);

	card takeCard(int cardPosition);

	card seeCard(int cardPosition);

	void drawPlayerCards(sf::RenderWindow& window, float x, float y, int& selectCard, card& usedCard, bool& pressSpace, int& turn, bool& pressEnter, int& countCards, bool& unoButtonPressed);

	void setCardTexture(sf::Texture& texture);

	void switchCard(int type, int color);

	void drawDeckCards(sf::RenderWindow& window, float x, float y);

	void takeCardFromDeck(bool& pressZ, Player& cardsSet, int& countCards, int& turn, bool& unoButtonPressed);

	void passTurn(int& turn, bool& unoButtonPressed);

	void changeCardColor(int& selectCard, bool& pressX);

	void activeUnoButtonNotPressed(bool& unoButtonPressed, Player& cardsSet);

	int getTotalCards();

private:

	std::vector<card> cards;
	sf::Sprite sprite;
	bool colorLock = false;
	int numberOfCards = 0;

	void playerActions(card& usedCard, bool& pressSpace, int& selectCard, int& turn, int& countCards, bool& unoButtonPressed);

	bool validColorCard(card& usedCard, int& selectCard);

	bool validCard(card& usedCard, int& selectCard, int& countCards);

};