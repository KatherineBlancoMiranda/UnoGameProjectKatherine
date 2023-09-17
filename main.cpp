#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "showusedcard.h"


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(900, 700), "Juego uno");
    sf::Texture texture;
    texture.loadFromFile("Cards.png");
    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    //sprite.setTextureRect(sf::IntRect(0, 0, 58, 86)); //cada 57 en x cada 86 en y



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

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }



        window.clear();

        playerOne.drawCards(window, 0, 0);
        playerTwo.drawCards(window, 0, 500);
        //window.draw(sprite);
        window.display();

    }

   /* while (true) {

        playerOne.doActions(&usedCard);
        playerTwo.doActions(&usedCard);

    }*/




}

//Si 13 se cambia color, si es igual a 14 se le agrega 4, 
//si es igual a 12 se le agrega 2, si es igual a 11 bloqueo, si es igual 10 reversa