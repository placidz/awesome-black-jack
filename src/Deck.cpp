#include "Deck.h"

#include <QCoreApplication>
#include <cstdlib>
#include <time.h>
#include "Card.h"

Deck::Deck()
{
	init();
}

void Deck::init()
{
	qDeleteAll(m_cards);
	m_cards.clear();

	m_cards.push_back(new Card(Ace, Diamond));
	m_cards.push_back(new Card(Two, Diamond));
	m_cards.push_back(new Card(Three, Diamond));
	m_cards.push_back(new Card(Four, Diamond));
	m_cards.push_back(new Card(Five, Diamond));
	m_cards.push_back(new Card(Six, Diamond));
	m_cards.push_back(new Card(Seven, Diamond));
	m_cards.push_back(new Card(Eight, Diamond));
	m_cards.push_back(new Card(Nine, Diamond));
	m_cards.push_back(new Card(Ten, Diamond));
	m_cards.push_back(new Card(Jack, Diamond, 10));
	m_cards.push_back(new Card(Queen, Diamond, 10));
	m_cards.push_back(new Card(King, Diamond, 10));

	m_cards.push_back(new Card(Ace, Spade));
	m_cards.push_back(new Card(Two, Spade));
	m_cards.push_back(new Card(Three, Spade));
	m_cards.push_back(new Card(Four, Spade));
	m_cards.push_back(new Card(Five, Spade));
	m_cards.push_back(new Card(Six, Spade));
	m_cards.push_back(new Card(Seven, Spade));
	m_cards.push_back(new Card(Eight, Spade));
	m_cards.push_back(new Card(Nine, Spade));
	m_cards.push_back(new Card(Ten, Spade));
	m_cards.push_back(new Card(Jack, Spade, 10));
	m_cards.push_back(new Card(Queen, Spade, 10));
	m_cards.push_back(new Card(King, Spade, 10));

	m_cards.push_back(new Card(Ace, Heart));
	m_cards.push_back(new Card(Two, Heart));
	m_cards.push_back(new Card(Three, Heart));
	m_cards.push_back(new Card(Four, Heart));
	m_cards.push_back(new Card(Five, Heart));
	m_cards.push_back(new Card(Six, Heart));
	m_cards.push_back(new Card(Seven, Heart));
	m_cards.push_back(new Card(Eight, Heart));
	m_cards.push_back(new Card(Nine, Heart));
	m_cards.push_back(new Card(Ten, Heart));
	m_cards.push_back(new Card(Jack, Heart, 10));
	m_cards.push_back(new Card(Queen, Heart, 10));
	m_cards.push_back(new Card(King, Heart, 10));

	m_cards.push_back(new Card(Ace, Club));
	m_cards.push_back(new Card(Two, Club));
	m_cards.push_back(new Card(Three, Club));
	m_cards.push_back(new Card(Four, Club));
	m_cards.push_back(new Card(Five, Club));
	m_cards.push_back(new Card(Six, Club));
	m_cards.push_back(new Card(Seven, Club));
	m_cards.push_back(new Card(Eight, Club));
	m_cards.push_back(new Card(Nine, Club));
	m_cards.push_back(new Card(Ten, Club));
	m_cards.push_back(new Card(Jack, Club, 10));
	m_cards.push_back(new Card(Queen, Club, 10));
	m_cards.push_back(new Card(King, Club, 10));
}

Card* Deck::getRandomCard()
{
	srand(time(NULL));
	int index = rand() % m_cards.size(); 
	return m_cards.takeAt(index);
}