#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "showusedcard.h"



void interactWithKeyboard(sf::RenderWindow& window, int& selectCard, int& turn, bool& pressSpace, bool& pressZ, bool& pressEnter) {

    sf::Event event;
    pressSpace = false;
    pressZ = false;
    pressEnter = false;

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {

            window.close();

        }

        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::Left) {

                selectCard--;

            }

            if (event.key.code == sf::Keyboard::Right) {

                selectCard++;

            }
            if (event.key.code == sf::Keyboard::Space) {


                pressSpace = true;

            }

            if (event.key.code == sf::Keyboard::Enter) {

                pressEnter = true;

            }

            if (event.key.code == sf::Keyboard::Z) {

                pressZ = true;
                
            }


        }
       

    }

}

void stopCard(int& lastTurn, card& usedCard, int& turn) {

    if (usedCard.type == 10) {

        turn = lastTurn;

    }
    lastTurn = turn;

}


using namespace std;

int main()
{
    int selectCard = 0;
    int turn = 1;
    bool pressSpace = false;
    bool pressEnter = false;
    bool pressZ = false;
    int countCards = 0;
    sf::RenderWindow window(sf::VideoMode(900, 700), "Juego uno");
    sf::Texture texture;
    texture.loadFromFile("Cards.png");


    int lastTurn = turn;

    srand(time(0));

    Player playerOne;
    Player playerTwo;
    Player cardsSet;
    card usedCard;

    playerOne.setCardTexture(texture);
    playerTwo.setCardTexture(texture);
    cardsSet.setCardTexture(texture);

    cardsSet.generateCards();
    cardsSet.shuffleCards();


    for (int i = 0; i < 8; i++) {

        playerOne.addCard(cardsSet.takeCard(0));
        playerTwo.addCard(cardsSet.takeCard(0));

    }

    cout << endl;
    cout << endl;
    cardsSet.showCards();
    cout << endl;
    cout << endl;

    usedCard = cardsSet.takeCard(0);
    showUsedCard(usedCard);
    cout << endl;
    cout << endl;

    cout << endl;
    cout << endl;
    playerOne.showCards();

    cout << endl;
    cout << endl;
    playerTwo.showCards();

    while (window.isOpen()) {

        interactWithKeyboard(window, selectCard, turn, pressSpace, pressZ, pressEnter);

        window.clear(sf::Color::White);

        cardsSet.drawDeckCards(window, 500, 250);

        if (turn > 2) {

            turn = 1;

        }

        stopCard(lastTurn, usedCard, turn);

        if (turn == 1) {

            playerOne.drawPlayerCards(window, 0, 0, selectCard, usedCard, pressSpace, turn, pressEnter, countCards);

            playerOne.takeCardFromDeck(pressZ, cardsSet, countCards, turn);

        }
        

        else {

            playerTwo.drawPlayerCards(window, 0, 450, selectCard, usedCard, pressSpace, turn, pressEnter, countCards);

            playerTwo.takeCardFromDeck(pressZ, cardsSet, countCards, turn);

        }
        
        window.display();

    }

   /* while (true) {

        playerOne.doActions(&usedCard);
        playerTwo.doActions(&usedCard);

    }*/




}
