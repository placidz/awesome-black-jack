#pragma once

#include "Card.h"
#include <QList>
#include <QString>

class BJPlayerInt
{
public:

	enum PlayerAction
	{
		None,
		Hit,
		Stand
	};

	virtual PlayerAction play() = 0;
	void addCard(Card* c)
	{
		m_cards.append(c);
	}

	QList<Card*> getCards()
	{
		return m_cards;
	}

	int computeScore()
	{
		int sum = 0;
		for( int i = 0 ; i < m_cards.count() ; ++i )
			sum += m_cards[i]->getValue();
		return sum;
	}

protected:

	QList<Card*> m_cards;
	QString m_playerName;

};