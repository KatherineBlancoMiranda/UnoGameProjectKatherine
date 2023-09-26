#include "stopcard.h"

void stopCard(int& lastTurn, card& usedCard, int& turn) {

    if (usedCard.type == 10) {

        turn = lastTurn;

    }
    lastTurn = turn;
}