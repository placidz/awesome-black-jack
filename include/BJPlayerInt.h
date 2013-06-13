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

protected:

	QList<Card*> m_cards;
	QString m_playerName;

};