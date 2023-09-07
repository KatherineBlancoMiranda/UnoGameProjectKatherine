#pragma once
#include <iostream>
#include <cstdlib>
#include "cardvariable.h"

using namespace std;

class Player {

private:

	std::vector<card> cards;
	

public:

	int selectedCard;

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

	card takeCard(int cardPosition) {				//Borré metodo takeInitialCard

		card temporalCard = cards[cardPosition];
		cards.erase(cards.begin() + cardPosition);
		return temporalCard;

	}

	card seeCard(int cardPosition) {				//Borré metodo takeInitialCard

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

};
