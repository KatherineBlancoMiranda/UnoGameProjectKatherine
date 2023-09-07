#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "showusedcard.h"

using namespace std;

int main()
{
    srand(time(0));

    Player playerOne;
    Player playerTwo;
    Player cardsSet;
    card usedCard;

    cardsSet.generateCards();
    cardsSet.shuffleCards();


    for (int i = 0; i < 8; i++) {

        playerOne.addCard(cardsSet.takeCard(0));
        playerTwo.addCard(cardsSet.takeCard(0));

    }

    cout << endl;
    cout << endl;
    playerOne.showCards();

    cout << endl;
    cout << endl;
    playerTwo.showCards();

    cout << endl;
    cout << endl;
    cardsSet.showCards();
    cout << endl;
    cout << endl;

    usedCard = cardsSet.takeCard(0);
    showUsedCard(usedCard);
    cout << endl;
    cout << endl;

    int selectCard;

    while (true) {

        playerOne.showCards();
        showUsedCard(usedCard);

        cin >> selectCard;

        if (playerOne.compareColors(selectCard, usedCard)) {

            usedCard = playerOne.takeCard(selectCard);
            
        }
        if (playerOne.compareType(selectCard, usedCard)) {

            usedCard = playerOne.takeCard(selectCard);

        }
        

    }




}

//Si mayor que 12 se cambia color, si es igual a 14 se le agrega 4, 
//si es igual a 12 se le agrega 2, si es igual a 11 bloqueo, si es igual 10 reversa