#pragma once

enum Rank 
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};

enum Suit
{
	Diamond,
	Spade,
	Heart,
	Club
};

class Card
{
public:
	Card(Rank _rank, Suit _suit);
	Card(Rank _rank, Suit _suit, int _value);
	~Card(void);

	Rank getRank() const { return m_rank; }
	Suit getSuit() const { return m_suit; }
	int getValue() const { return m_value; }

	bool operator>(const Card & _card) const;
	bool operator<(const Card & _card) const;

private:
	Rank m_rank;
	Suit m_suit;
	int m_value;
};

