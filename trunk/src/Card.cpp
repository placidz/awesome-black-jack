#include "Card.h"


Card::Card(Rank _rank, Suit _suit)
	: m_rank(_rank), m_suit(_suit)
{
}


Card::~Card(void)
{
}

bool Card::operator>(const Card & _card) const
{
	if (m_rank > _card.getRank())
		return true;
	else if (m_rank == _card.getRank() && m_suit > _card.getSuit())
		return true;
	return false;
}

bool Card::operator<(const Card & _card) const
{
	return (_card > *this);
}
