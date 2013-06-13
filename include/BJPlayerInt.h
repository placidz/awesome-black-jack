#pragma once

class BJPlayerInt
{
public:

	enum PlayerAction
	{
		Hit,
		Stand
	};

	virtual PlayerAction play() = 0;

};