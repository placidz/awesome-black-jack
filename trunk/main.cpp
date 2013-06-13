#include <QtCore/QCoreApplication>
#include "bjapplication.h"
#include <time.h>
#include <iostream>

int displaySum(const std::string &name, const QList<int>& l, bool isDealer = false);
int getCard();
int getSum(const QList<int>& l);
std::string cardValueToStr(int value);

int main(int argc, char *argv[])
{
//    BJackApplication a(argc, argv);
	qsrand(time(NULL));
	int playerMoney = 100;
	int betFactor = 1;

	while (playerMoney > 0)
	{
		betFactor = 1;
		bool finished = false;
		QList<int> player;
		QList<int> dealer;
		player.append(getCard());
		player.append(getCard());
		dealer.append(getCard());
		dealer.append(getCard());

		std::cout << "Oi e bem-vindo Alex ao Super Blackjack !!!" << std::endl << "Your amount of money: " << playerMoney << std::endl << std::endl;
		int dealerSum = 0;
		int playerSum = 0;
		while( !finished )
		{
			dealerSum = displaySum("Dealer", dealer, true);
			playerSum = displaySum("Player", player);
		
			if( betFactor != 1 || playerSum >= 21 )
				finished = true;
			else
			{
				std::cout << "H (hit) - S (stand) - D (double): ";
				char c;
				std::cin >> c;

				if( c == 'S' || c == 's' )
					finished = true;
				else if( c == 'D' || c == 'd' )
				{
					betFactor = 2;
					player.append(getCard());
				}
				else
					player.append(getCard());
			}
		}
		while( (playerSum < 22 && dealerSum <= playerSum) && playerSum != 21 )
		{
			dealer.append(getCard());
			dealerSum = getSum(dealer);
		}

		std::cout << std::endl;
		displaySum("Cards of the Dealer", dealer);

		std::cout << "Dealer: " << dealerSum << std::endl;
		std::cout << "Player: " << playerSum << std::endl;

		if( playerSum > 21 )
		{	if( dealerSum == 21 )
				std::cout << "BLACKJACK !!!" << std::endl;
			playerMoney -= (10*betFactor);
			std::cout << "You loose! Your amount of money = " << playerMoney << std::endl;
		}
		else if( dealerSum > 21 )
		{
			if( playerSum == 21 )
				std::cout << "BLACKJACK !!!" << std::endl;
			playerMoney += (10*betFactor);
			std::cout << "You win! Your amount of money = " << playerMoney << std::endl;
		}
		else
		{
			if( playerSum == dealerSum )
				std::cout << "Push! Your amount of money = " << playerMoney << std::endl;
			else
			{
				if( dealerSum == 21 || playerSum == 21 )
					std::cout << "BLACKJACK !!!" << std::endl;
				if( playerSum > dealerSum )
				{
					playerMoney += (10*betFactor);
					std::cout << "You win! Your amount of money = " << playerMoney << std::endl;
				}
				else
				{
					playerMoney -= (10*betFactor);
					std::cout << "You loose! Your amount of money = " << playerMoney << std::endl;
				}
			}
			
		}

		if( playerMoney <= 0 )
			std::cout << std::endl << "You don't have money anymore! Out of the CASINO!" << std::endl << std::endl;

		system("PAUSE");
		system("CLS");
	}
    return 0;
}

int displaySum(const std::string &name, const QList<int>& l, bool isDealer)
{
	std::cout << name << ": ";
	int sum = getSum(l);
	for( int i = 0 ; i < l.count() ; ++i )
	{
		if( isDealer )
		{
			if( i == 0 )
				std::cout << cardValueToStr(l[i]) << ", ";
			else
				std::cout << "*";
		}
		else
		{
			if( i != l.count()-1 )
				std::cout << cardValueToStr(l[i]) << ", ";
			else
				std::cout << cardValueToStr(l[i]);
		}
	}

	if( isDealer )
		std::cout << std::endl;
	else
		std::cout << " (" << sum << ")" << std::endl;
	
	return sum;
}

int getSum(const QList<int>& l)
{
	int sum = 0;
	for( int i = 0 ; i < l.count() ; ++i )
		sum += qMin(l[i], 10);

	return sum;
}

int getCard()
{
	if( qrand() % 4 == 0 )
		return qrand() % 3 + 12;

	return qrand() % 9 + 2;
}

std::string cardValueToStr(int value) {
	if(value < 11) {
		char v[2];
		_itoa(value, v, 10);
		return std::string(v);
	}
	switch (value)
	{
	case 12: return "J";
	case 13: return "Q";
	case 14: return "K";
	default:
		return "A";
	}
}