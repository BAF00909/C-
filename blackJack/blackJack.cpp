#include <iostream>
#include <locale>
using namespace std;
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"
#include "Game.h"
#include <cstdlib>


void blackJackMain() {

    srand(time(0));

    string pl1 = "Alex";
    string pl2 = "Ann";
    vector<string> players;
    players.push_back(pl1);
    players.push_back(pl2);

    Game game(players);

    char again = 'y';
    while(again != 'n' && again != 'N')
    {
        game.play();
        cout << "\n Сыграете еще раз? (Y/N): \n";
        cin >> again;
    }


}



int main()
{
    setlocale(LC_ALL, "Russian");

    blackJackMain();

    return 0;
}