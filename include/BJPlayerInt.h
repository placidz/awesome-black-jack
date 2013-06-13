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

protected:

	QList<Card*> m_cards;
	QString m_playerName;

};