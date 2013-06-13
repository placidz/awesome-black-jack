#pragma once

class Card;

class Deck
{
public:
	Deck();
	~Deck(void);

private:
	std::list<Card> m_cards;
};

