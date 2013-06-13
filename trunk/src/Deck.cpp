#include "Deck.h"

#include "Card.h"

Deck::Deck()
{
	init();
}

void Deck::init()
{
	m_cards.clear();

	m_cards.push_back(Card(Ace, Diamond));
	m_cards.push_back(Card(Two, Diamond));
	m_cards.push_back(Card(Three, Diamond));
	m_cards.push_back(Card(Four, Diamond));
	m_cards.push_back(Card(Five, Diamond));
	m_cards.push_back(Card(Six, Diamond));
	m_cards.push_back(Card(Seven, Diamond));
	m_cards.push_back(Card(Eight, Diamond));
	m_cards.push_back(Card(Nine, Diamond));
	m_cards.push_back(Card(Ten, Diamond));
	m_cards.push_back(Card(Jack, Diamond));
	m_cards.push_back(Card(Queen, Diamond));
	m_cards.push_back(Card(King, Diamond));

	m_cards.push_back(Card(Ace, Spade));
	m_cards.push_back(Card(Two, Spade));
	m_cards.push_back(Card(Three, Spade));
	m_cards.push_back(Card(Four, Spade));
	m_cards.push_back(Card(Five, Spade));
	m_cards.push_back(Card(Six, Spade));
	m_cards.push_back(Card(Seven, Spade));
	m_cards.push_back(Card(Eight, Spade));
	m_cards.push_back(Card(Nine, Spade));
	m_cards.push_back(Card(Ten, Spade));
	m_cards.push_back(Card(Jack, Spade));
	m_cards.push_back(Card(Queen, Spade));
	m_cards.push_back(Card(King, Spade));

	m_cards.push_back(Card(Ace, Heart));
	m_cards.push_back(Card(Two, Heart));
	m_cards.push_back(Card(Three, Heart));
	m_cards.push_back(Card(Four, Heart));
	m_cards.push_back(Card(Five, Heart));
	m_cards.push_back(Card(Six, Heart));
	m_cards.push_back(Card(Seven, Heart));
	m_cards.push_back(Card(Eight, Heart));
	m_cards.push_back(Card(Nine, Heart));
	m_cards.push_back(Card(Ten, Heart));
	m_cards.push_back(Card(Jack, Heart));
	m_cards.push_back(Card(Queen, Heart));
	m_cards.push_back(Card(King, Heart));

	m_cards.push_back(Card(Ace, Club));
	m_cards.push_back(Card(Two, Club));
	m_cards.push_back(Card(Three, Club));
	m_cards.push_back(Card(Four, Club));
	m_cards.push_back(Card(Five, Club));
	m_cards.push_back(Card(Six, Club));
	m_cards.push_back(Card(Seven, Club));
	m_cards.push_back(Card(Eight, Club));
	m_cards.push_back(Card(Nine, Club));
	m_cards.push_back(Card(Ten, Club));
	m_cards.push_back(Card(Jack, Club));
	m_cards.push_back(Card(Queen, Club));
	m_cards.push_back(Card(King, Club));
}