#pragma once

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

};