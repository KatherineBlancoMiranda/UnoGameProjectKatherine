#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "classplayer.h"

Player::Player(){}

void Player::generateCards()
{
	int count = 1;

	for (int i = 0; i < 4; i++) {

		cards.push_back({ 0, i });

		for (int j = 0; j < 24; j++) {

			cards.push_back({ count, i });
			count++;
//Cambiar por la función MIN
			if (count >= 13) {

				count = 1;

			}

		}

		cards.push_back({ 13, 3 });
		cards.push_back({ 14, 3 });

	}
}

void Player::shuffleCards()
{
	for (int i = 0; i < 222; i++) {

		int aux = rand() % 107;
		cards.push_back({ cards[aux].type, cards[aux].color });
		cards.erase(cards.begin() + aux);

	}
}

void Player::addCard(card aCard)
{
	cards.push_back(aCard);
}

card Player::takeCard(int cardPosition)
{
	card temporalCard = cards[cardPosition];
	cards.erase(cards.begin() + cardPosition);
	return temporalCard;
}

card Player::seeCard(int cardPosition)
{
	return cards[cardPosition];
}

void Player::drawPlayerCards(sf::RenderWindow& window, float x, float y, int& selectCard, card& usedCard, bool& pressSpace, int& turn, bool& pressEnter, int& countCards, bool& unoButtonPressed)
{
	if (selectCard < 0) {

		selectCard = 0;

	}
	if (selectCard > cards.size() - 1) {

		selectCard = cards.size() - 1;

	}

	sprite.setPosition(x, y);

	for (int i = 0; i < cards.size(); i++) {

		if (sprite.getPosition().x > 900) {

			y = y + 100;
			sprite.setPosition(x, y);

		}

		switchCard(cards[i].type, cards[i].color);
		if (selectCard == i) {

			sprite.move(0, 30);

		}

		window.draw(sprite);
		sprite.move(70, 0);
		sprite.setPosition(sprite.getPosition().x, y);

	}

	sprite.setPosition(0, 250);
	switchCard(usedCard.type, usedCard.color);
	window.draw(sprite);
	playerActions(usedCard, pressSpace, selectCard, turn, countCards, unoButtonPressed);


	if (pressEnter && countCards == 0) {

		passTurn(turn, unoButtonPressed);

	}
}

void Player::setCardTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Player::switchCard(int type, int color)
{
	sprite.setTextureRect(sf::IntRect(type * 57, color * 86, 57, 86));
}

void Player::drawDeckCards(sf::RenderWindow& window, float x, float y)
{
	sprite.setPosition(x, y);
	switchCard(cards[0].type, cards[0].color);
	window.draw(sprite);
}

void Player::takeCardFromDeck(bool& pressZ, Player& cardsSet, int& countCards, int& turn, bool& unoButtonPressed)
{
	if (pressZ && cards.size() < 24) {

		addCard(cardsSet.takeCard(0));
		numberOfCards++;

		if (countCards > 0) {
		//Evitar tantas anidaciones
			for (int i = 0; i < countCards; i++) {

				addCard(cardsSet.takeCard(0));

			}
			countCards = 0;
			passTurn(turn, unoButtonPressed);
		}

	}
}

void Player::passTurn(int& turn, bool& unoButtonPressed)
{
	turn++;
	colorLock = false;
	numberOfCards = 0;
	unoButtonPressed = false;
}

void Player::changeCardColor(int& selectCard, bool& pressX)
{
	if (!pressX) {

		return;

	}
	if (cards[selectCard].type < 13) {

		return;
	}
	cards[selectCard].color++;
	if (cards[selectCard].color > 3) {

		cards[selectCard].color = 0;

	}
}

void Player::activeUnoButtonNotPressed(bool& unoButtonPressed, Player& cardsSet)
{
	if (!unoButtonPressed && cards.size() == 1) {

		for (int i = 0; i < 2; i++) {

			addCard(cardsSet.takeCard(0));

		}

	}
}

int Player::getTotalCards()
{
	return cards.size();
}

void Player::playerActions(card& usedCard, bool& pressSpace, int& selectCard, int& turn, int& countCards, bool& unoButtonPressed)
{
	if (pressSpace && validCard(usedCard, selectCard, countCards)) {

		card tempCard = usedCard;

		if (validColorCard(usedCard, selectCard)) {

			usedCard = takeCard(selectCard);
			//Evitar tantas anidaciones 
			if (usedCard.type == 14) {

				passTurn(turn, unoButtonPressed);
				countCards = countCards + 4;


			}
			if (usedCard.type == 12) {

				passTurn(turn, unoButtonPressed);
				countCards = countCards + 2;


			}

			colorLock = true;
			if (tempCard.color != usedCard.color) {

				passTurn(turn, unoButtonPressed);

			}
		}
	}
}

bool Player::validColorCard(card& usedCard, int& selectCard)
{
	if (!colorLock) {

		return true;

	}

	if (usedCard.color == cards[selectCard].color) {

		return true;

	}

	return false;
}

bool Player::validCard(card& usedCard, int& selectCard, int& countCards)
{
	//Utilice variables para mejorar la lectura de las expresiones y evite los numeros mágicos
	if (countCards > 0) {

		if (seeCard(selectCard).type == 14) {

			return true;

		}

		if (seeCard(selectCard).type == 12) {

			return true;

		}

		return false;

	}

	if (seeCard(selectCard).color == usedCard.color) {

		return true;

	}

	if (seeCard(selectCard).type == usedCard.type) {

		return true;

	}

	if (seeCard(selectCard).type == 13 || seeCard(selectCard).type == 14) {

		return true;

	}
	return false;
}