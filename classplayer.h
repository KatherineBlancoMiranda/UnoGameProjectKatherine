#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "cardvariable.h"
#include "showusedcard.h"

using namespace std;

class Player {

public:

	Player() {

	}

	void doActions(card* usedCard) {

		int cardSelection;

		showCards();
		

		cin >> cardSelection;

		if (compareColors(cardSelection, *usedCard)|| compareType(cardSelection, *usedCard)) {

			*usedCard = takeCard(cardSelection);

		}

		showUsedCard(*usedCard);

	}

	void generateCards() {

		int count = 1;

		for (int i = 0; i < 4; i++) {

			cards.push_back({ 0, i });

			for (int j = 0; j < 24; j++) {

				cards.push_back({ count, i });
				count++;

				if (count >= 13) {

					count = 1;

				}

			}

			cards.push_back({ 13, 3 });
			cards.push_back({ 14, 3 });

		}

	}

	void shuffleCards() {

		for (int i = 0; i < 222; i++) {

			int aux = rand() % 107;
			cards.push_back({ cards[aux].type, cards[aux].color });
			cards.erase(cards.begin() + aux);

		}

	}

	void showCards() {

		for (int i = 0; i < cards.size(); i++) {

			cout << "Tipo: " << cards[i].type << " ";
			cout << "Color: " << cards[i].color;
			cout << endl;

		}
		cout << cards.size();
		cout << endl;

	}

	void addCard(card aCard) {

		cards.push_back(aCard);

	}

	card takeCard(int cardPosition) {				

		card temporalCard = cards[cardPosition];
		cards.erase(cards.begin() + cardPosition);
		return temporalCard;

	}

	card seeCard(int cardPosition) {				

		return cards[cardPosition];

	}

	bool compareColors(int cardPosition, card usedCard) {

		if (seeCard(cardPosition).color == usedCard.color) {

			return true;
		}

		return false;

	}

	bool compareType(int cardPosition, card usedCard) {

		if (seeCard(cardPosition).type == usedCard.type) {

			return true;
		}

		return false;

	}

	void drawPlayerCards(sf:: RenderWindow &window, float x, float y, int& selectCard, card& usedCard, bool& pressSpace) {

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
		playerActions(usedCard, pressSpace, selectCard);

	}

	void setCardTexture(sf:: Texture &texture) {

		sprite.setTexture(texture);


	}

	void switchCard(int type,  int color) {

		sprite.setTextureRect(sf::IntRect(type*57, color*86, 57, 86));

	}

	void drawDeckCards(sf::RenderWindow& window, float x, float y) {

		sprite.setPosition(x, y);
		switchCard(cards[0].type, cards[0].color);
		window.draw(sprite);

	}

	void takeCardFromDeck(bool& pressZ, Player& cardsSet) {

		if (pressZ && cards.size() < 24) {

			addCard(cardsSet.takeCard(0));

		}

	}


private:

	std::vector<card> cards;
	sf::Sprite sprite;

	void playerActions(card& usedCard, bool& pressSpace, int& selectCard) {

		if (pressSpace&&validCard(usedCard, selectCard)) {

			usedCard = takeCard(selectCard);
		}

	}

	bool validCard(card usedCard, int selectCard) {

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

};