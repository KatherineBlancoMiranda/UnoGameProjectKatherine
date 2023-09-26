#include "zerocard.h"

void zeroCard(Player& playerOne, Player& playerTwo, card& usedCard) {

    Player savePlayerCards;

    if (!usedCard.effect) {

        return;

    }

    if (usedCard.type == 0) {

        Player savePlayerCards = playerOne;
        playerOne = playerTwo;
        playerTwo = savePlayerCards;

    }
    usedCard.effect = false;
}