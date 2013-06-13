#pragma once

#include "BJPlayerInt.h"

class BJComputerPlayer : public BJPlayerInt
{
public:

	BJComputerPlayer();
	BJPlayerInt::PlayerAction play();
};