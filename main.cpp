#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


struct card {

    int type, color;

};

std::vector<card> cards;
std::vector<card> playerCards;
std::vector<card> player2Cards;


void showCards() {

    for (int i = 0; i < cards.size(); i++) {

        cout << cards[i].type << " ";
        cout << cards[i].color << " ";
        cout << endl;

    }
    cout << cards.size();

}




int main()
{

    srand(time(0));
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

    //Si mayor que 12 se cambia color, si es igual a 14 se le agrega 4, 
    //si es igual a 12 se le agrega 2, si es igual a 11 bloqueo, si es igual 10 reversa
   

    showCards();

    
    cout << endl <<"------------------------------"<< endl <<"---------------------" << endl;

    for (int i = 0; i < 222; i++) {


        int aux = rand() % 107;
        cards.push_back({ cards[aux].type, cards[aux].color});
        cards.erase(cards.begin() + aux);

    }

    showCards();

    
    for (int i = 0; i < 8; i++) {

        playerCards.push_back({ cards[0].type, cards[0].color });
        cards.erase(cards.begin());

    }

    cout << endl << "------------------------------" << endl << "---------------------" << endl;
    showCards();
  
    cout << endl << "------------------------------" << endl << "---------------------" << endl;

    for (int i = 0; i < playerCards.size(); i++) {

        cout << playerCards[i].type << " ";
        cout << playerCards[i].color << " ";
        cout << endl;

    }


}
