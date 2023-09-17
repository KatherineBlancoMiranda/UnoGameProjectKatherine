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

		sprite.setTextureRect(sf::IntRect(0, 0, 57, 86));
		switchCard(4, 3);

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

			cards.push_back({ 13, 5 });
			cards.push_back({ 14, 5 });

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

	void drawCards(sf:: RenderWindow &window, float x, float y) {

		sprite.setPosition(x, y);

		for (int i = 0; i < cards.size(); i++) {

			switchCard(cards[i].type, cards[i].color);
			window.draw(sprite);
			sprite.move(70, 0);

		}


		//window.draw(sprite);

	}

	void setCardTexture(sf:: Texture &texture) {

		sprite.setTexture(texture);


	}

	void switchCard(int type,  int color) {

		sprite.setTextureRect(sf::IntRect(type*57, color*86, 57, 86));

	}


private:

	std::vector<card> cards;
	sf::Sprite sprite;

	


};
