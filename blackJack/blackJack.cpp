#include <iostream>
#include <locale>
using namespace std;
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "House.h"




int main()
{
    setlocale(LC_ALL, "Russian");

    Card spadesAce(Card::valueCard::ACE, Card::cardSuit::SPADES, false);
    spadesAce.flip();
    cout << spadesAce << endl;

    Card* sa = &spadesAce;

    Player pl("Alexandr");
    pl.add(sa);
    cout << pl.getValue() << endl;

    House dil("Diller");
    dil.add(sa);
    cout << dil.getValue() << endl;

    return 0;
}