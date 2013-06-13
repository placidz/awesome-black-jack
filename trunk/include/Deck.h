#pragma once

#include <list>
class Card;

class Deck
{
public:
	Deck();
	~Deck(void);

	void init();

	Card getRandomCard();

private:
	std::list<Card> m_cards;
};

