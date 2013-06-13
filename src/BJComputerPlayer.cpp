#include "BJComputerPlayer.h"
#include <QCoreApplication>

BJComputerPlayer::BJComputerPlayer()
{
	m_playerName = QString("Computer");
}

BJPlayerInt::PlayerAction BJComputerPlayer::play()
{
	int action = qrand() % 2 + 1;

	switch( action )
	{
	case 1:
		return BJPlayerInt::Hit;
	case 2:
		return BJPlayerInt::Stand;

	default:
		return BJPlayerInt::None;
	}
}