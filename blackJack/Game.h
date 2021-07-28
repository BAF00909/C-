#pragma once
#include <iostream>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
public:
	Deck deck;
	House * diller = new House("Крупье");
	std::vector<Player> players;
	void play();
	Game(std::vector<string> names);
};