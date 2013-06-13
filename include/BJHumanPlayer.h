#pragma once

#include "BJPlayerInt.h"

class BJHumanPlayer : public BJPlayerInt
{
public:

	BJHumanPlayer(const QString &pName);
	BJPlayerInt::PlayerAction play();
};