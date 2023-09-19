#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "showusedcard.h"



void interactWithKeyboard(sf::RenderWindow& window, int& selectCard, int& turn, bool& pressSpace) {

    sf::Event event;
    pressSpace = false;

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

                if (turn == 1) {

                    turn = 2;
                    
                }

                else {

                    turn = 1;

                }

            }


        }
       

    }

}


using namespace std;

int main()
{
    int selectCard = 0;
    int turn = 1;
    bool pressSpace = false;
    sf::RenderWindow window(sf::VideoMode(900, 700), "Juego uno");
    sf::Texture texture;
    texture.loadFromFile("Cards.png");



    srand(time(0));

    Player playerOne;
    Player playerTwo;
    Player cardsSet;
    card usedCard;

    playerOne.setCardTexture(texture);
    playerTwo.setCardTexture(texture);

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

        interactWithKeyboard(window, selectCard, turn, pressSpace);

        window.clear(sf::Color::White);

        if (turn == 1) {

            playerOne.drawCards(window, 0, 0, selectCard, usedCard, pressSpace);

            /*if (pressSpace) {

                usedCard = playerOne.takeCard(selectCard);
                
            }*/
            
        }
        if (turn == 2) {

            playerTwo.drawCards(window, 0, 500, selectCard, usedCard, pressSpace);

            /*if (pressSpace) {

                usedCard = playerTwo.takeCard(selectCard);
            }*/

        }
        
        window.display();

    }

   /* while (true) {

        playerOne.doActions(&usedCard);
        playerTwo.doActions(&usedCard);

    }*/




}

//Si 13 se cambia color, si es igual a 14 se le agrega 4, 
//si es igual a 12 se le agrega 2, si es igual a 11 bloqueo, si es igual 10 reversa