#include "BJHumanPlayer.h"
#include <iostream>

BJHumanPlayer::BJHumanPlayer(const QString &pName)
{
	m_playerName = pName;
}

BJPlayerInt::PlayerAction BJHumanPlayer::play()
{
	int action = 0;
	std::cout << "Actions: 1-Hit, 2-Stand" << std::endl;
	std::cin >> action;

	switch(action)
	{
	case 1:
		return BJPlayerInt::Hit;
	case 2:
		return BJPlayerInt::Stand;
	default:
		return BJPlayerInt::None;
	}
}