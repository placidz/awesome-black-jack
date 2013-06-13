#include <QtCore/QCoreApplication>
#include "bjapplication.h"
#include <time.h>
#include <iostream>

int displaySum(const std::string &name, const QList<int>& l, bool isDealer = false);
int getCard();
int getSum(const QList<int>& l);
char cardValueToStr(int value);

int main(int argc, char *argv[])
{
//    BJackApplication a(argc, argv);
	qsrand(time(NULL));

	while (true)
	{
		bool finished = false;
		QList<int> player;
		QList<int> dealer;
		player.append(getCard());
		player.append(getCard());
		dealer.append(getCard());
		dealer.append(getCard());

		std::cout << "Oi e bem-vindo ao Super Blackjack !!!" << std::endl << std::endl;
		int dealerSum = 0;
		int playerSum = 0;
		while( !finished )
		{
			dealerSum = displaySum("Dealer", dealer, true);
			playerSum = displaySum("Player", player);
			std::cout << std::endl;
		
			if( playerSum >= 21 )
				finished = true;
			else
			{
				std::cout << "H (hit) - S (stand): ";
				char c;
				std::cin >> c;

				if( c == 'S' || c == 's' )
					finished = true;
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
			std::cout << "You loose!" << std::endl;
		}
		else if( dealerSum > 21 )
		{
			if( playerSum == 21 )
				std::cout << "BLACKJACK !!!" << std::endl;
			std::cout << "You win!" << std::endl;
		}
		else
		{
			if( playerSum == dealerSum )
				std::cout << "Push!" << std::endl;
			else
			{
				if( dealerSum == 21 || playerSum == 21 )
					std::cout << "BLACKJACK !!!" << std::endl;
				if( playerSum > dealerSum )
					std::cout << "You win!" << std::endl;
				else
					std::cout << "You loose!" << std::endl;
			}
			
		}

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
	for( int i = 0 ; i < l.count() ; ++i ) {

		sum += qMin(l[i], 10);
	}
	return sum;
}

int getCard()
{
	if( qrand() % 4 == 0 )
		return qrand() % 3 + 12;
	
	return qrand() % 9 + 2;
}

char cardValueToStr(int value) {
	if(value < 11)
		return value + '0';
	switch (value)
	{
	case 12: return 'J';
	case 13: return 'Q';
	case 14: return 'K';
	default:
		return 'A';
	}
}