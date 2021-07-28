#include "Game.h"

Game::Game(std::vector<string> names) {
	for (auto & name : names)
	{
		players.push_back(Player(name));
	}
};

void Game::play() {
	
	for (auto & player : players)
	{
		deck.Deal(player);
		deck.Deal(player);
	}
	deck.Deal(*diller);

	diller->flipFirstCard();

    system("cls");
    cout << "Карты " << diller->getName() << " : ";
    for (auto& card : diller->cards)
    {
        cout << *card << " ";
    }
    cout << endl;

    for (auto& player : players)
    {
        cout << "Карты " << player.getName() << " : ";
        for (auto& card : player.cards)
        {
            cout << *card << " ";
        }
        cout << endl;
    }

    for (auto& player : players) {
        cout << player.getName() << " ";
        while (player.isHitting()) {
           deck.AddItionalCards(player);
           system("cls");
           cout << "Карты " << diller->getName() << " : ";
           for (auto& card : diller->cards)
           {
               cout << *card << " ";
           }
           cout << endl;

           for (auto& player : players)
           {
               cout << "Карты " << player.getName() << " : ";
               for (auto& card : player.cards)
               {
                   cout << *card << " ";
               }
               cout << endl;
           }
        }
    }

    diller->flipFirstCard();
    while (diller->isHitting()){
        deck.AddItionalCards(*diller);
        system("cls");
        cout << "Карты " << diller->getName() << " : ";
        for (auto& card : diller->cards)
        {
            cout << *card << " ";
        }
        cout << endl;

        for (auto& player : players)
        {
            cout << "Карты " << player.getName() << " : ";
            for (auto& card : player.cards)
            {
                cout << *card << " ";
            }
            cout << endl;
        }
    }

    cout << diller->getName() << " счет: " << diller->getValue() << endl;
    for (auto player : players)
    {
        cout << player.getName() << " счет: " << player.getValue() << endl;
    }

    if (diller->isBoosted())
    {
        for (auto player : players)
        {
            if (!player.isBoosted())
            {
                player.win();
            }
        }
    }
    else
    {
        for (auto player : players)
        {
            if (!player.isBoosted() && player.getValue() > diller->getValue())
            {
                player.win();
            }
            else if (player.getValue() < diller->getValue())
            {
                player.lose();
            }
            else
            {
                player.push();
            }
        }
    }

    diller->clear();
    vector<Player>::iterator it = players.begin();
    for (it; it != players.end(); it++)
    {
        it->clear();
    }
    deck.clear();

}