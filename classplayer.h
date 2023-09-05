#pragma once
#include <iostream>
#include <cstdlib>
#include "cardvariable.h"

using namespace std;

class Player {

private:

	std::vector<card> cards;
	bool turn;

public:

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

			cout << cards[i].type << " ";
			cout << cards[i].color;
			cout << endl;

		}
		cout << cards.size();

	}

	void takeInitialCards() {

		for (int i = 0; i < 8; i++) {

			cards.push_back({ cards[0].type, cards[0].color });
			cards.erase(cards.begin());

		}

	}

	void addCard(card aCard) {

		cards.push_back(aCard);

	}

	card takeCard() {

		card temporalCard = cards[0];
		cards.erase(cards.begin());
		return temporalCard;
		

	}

};