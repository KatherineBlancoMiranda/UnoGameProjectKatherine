#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"

using namespace std;

int main()
{
    srand(time(0));

    Player playerOne;
    Player playerTwo;
    Player cardsSet;

    cardsSet.generateCards();
    cardsSet.showCards();
    cout << endl;
    cout << endl;
    cardsSet.shuffleCards();
    cout << endl;
    cout << endl;
    cardsSet.showCards();
    cout << endl;
    cout << endl;

    for (int i = 0; i < 8; i++) {

        playerOne.addCard(cardsSet.takeCard());
        playerTwo.addCard(cardsSet.takeCard());

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








}

//Si mayor que 12 se cambia color, si es igual a 14 se le agrega 4, 
//si es igual a 12 se le agrega 2, si es igual a 11 bloqueo, si es igual 10 reversa