#include <iostream>
#include <algorithm>
#include "Deck.h"
#define COUNTCARD 52


Deck::Deck() {
	Populate();
	Shuffle();
}
void Deck::Populate() {
	/*
	* наверное ћожно было через два цикла сделать генерацию ссылок, но решил забить руками, т.к тогда не надо дописывать ассоциацию 
	* дл€ мастей и значений
	*/
	/*пики*/

	deck.add(new Card(Card::valueCard::ACE, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::TWO, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::THREE, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::FOUR, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::FIVE, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::SIX, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::SEVEN, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::EIGHT, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::NINE, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::TEN, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::JACK, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::LADY, Card::cardSuit::SPADES, true));
	deck.add(new Card(Card::valueCard::KING, Card::cardSuit::SPADES, true));

	/*червы*/
	
	deck.add(new Card(Card::valueCard::ACE, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::TWO, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::THREE, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::FOUR, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::FIVE, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::SIX, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::SEVEN, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::EIGHT, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::NINE, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::TEN, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::JACK, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::LADY, Card::cardSuit::HEARDS, true));
	deck.add(new Card(Card::valueCard::KING, Card::cardSuit::HEARDS, true));

	/*бубны*/
	deck.add(new Card(Card::valueCard::ACE, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::TWO, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::THREE, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::FOUR, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::FIVE, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::SIX, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::SEVEN, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::EIGHT, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::NINE, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::TEN, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::JACK, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::LADY, Card::cardSuit::DIAMONDS, true));
	deck.add(new Card(Card::valueCard::KING, Card::cardSuit::DIAMONDS, true));

	/*трефы*/
	deck.add(new Card(Card::valueCard::ACE, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::TWO, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::THREE, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::FOUR, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::FIVE, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::SIX, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::SEVEN, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::EIGHT, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::NINE, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::TEN, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::JACK, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::LADY, Card::cardSuit::CLUBS, true));
	deck.add(new Card(Card::valueCard::KING, Card::cardSuit::CLUBS, true));
}

void Deck::Shuffle() {
	std::random_shuffle(deck.cards.begin(), deck.cards.end());
}

void Deck::Deal(Hand& aHand) {
	aHand.add(deck.cards.at(curentCardCount));
	curentCardCount++;
}
void Deck::AddItionalCards(GenericPlayer& aGenerlcPlayer) {
	aGenerlcPlayer.add(deck.cards.at(curentCardCount));
	curentCardCount++;
};