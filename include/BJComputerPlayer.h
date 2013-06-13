#pragma once

#include "BJPlayerInt.h"

class BJComputerPlayer : public BJPlayerInt
{
public:

	BJPlayerInt::PlayerAction play();
};