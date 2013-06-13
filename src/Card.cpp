#include "Card.h"

Card::Card(Rank _rank, Suit _suit)
	: m_rank(_rank), m_suit(_suit)
{
	m_value = m_rank;
}

Card::Card(Rank _rank, Suit _suit, int _value)
	: m_rank(_rank), m_suit(_suit), m_value(_value)
{
}


Card::~Card(void)
{
}

bool Card::operator>(const Card & _card) const
{
	return getValue() > _card.getValue();
}

bool Card::operator<(const Card & _card) const
{
	return (_card > *this);
}
