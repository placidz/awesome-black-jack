#pragma once

#include <QList>
class Card;

class Deck
{
public:
	Deck();
	~Deck(void);

	void init();

	Card* getRandomCard();

private:
	QList<Card*> m_cards;
};

