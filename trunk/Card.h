#pragma once

enum Rank 
{
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
	King,
	Ace
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
	~Card(void);

	Rank getRank() const { return m_rank; }
	Suit getSuit() const { return m_suit; }

	bool operator>(const Card & _card) const;
	bool operator<(const Card & _card) const;

private:
	Rank m_rank;
	Suit m_suit;
};

