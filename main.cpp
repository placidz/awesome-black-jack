#include <QtCore/QCoreApplication>
#include "bjapplication.h"
#include <time.h>
#include <iostream>

int displaySum(const std::string &name, const QList<int>& l, bool isDealer = false);
int getCard(const QList<int>& listing, const QList<int>& listing2);
int getSum(const QList<int>& l);
std::string cardValueToStr(int value);
void blackJack();
void casino();
void sexy() ;
void getout();

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
		player.append(getCard(player, dealer));
		player.append(getCard(player, dealer));
		dealer.append(getCard(player, dealer));
		dealer.append(getCard(player, dealer));
		casino();
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
					player.append(getCard(player, dealer));
				}
				else
					player.append(getCard(player, dealer));
			}
		}
		while( (playerSum < 22 && dealerSum <= playerSum) && playerSum != 21 )
		{
			dealer.append(getCard(player, dealer));
			dealerSum = getSum(dealer);
		}

		std::cout << std::endl;
		displaySum("Cards of the Dealer", dealer);

		std::cout << "Dealer: " << dealerSum << std::endl;
		std::cout << "Player: " << playerSum << std::endl;

		if( playerSum > 21 )
		{	if( dealerSum == 21 )
				blackJack();
				//std::cout << "BLACKJACK !!!" << std::endl;
			playerMoney -= (10*betFactor);
			std::cout << "You loose! Your amount of money = " << playerMoney << std::endl;
		}
		else if( dealerSum > 21 )
		{
			if( playerSum == 21 )
				blackJack();
				//std::cout << "BLACKJACK !!!" << std::endl;
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
					blackJack();
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

		if( playerMoney > 150 )
			sexy();

		if( playerMoney <= 0 ) {
			getout();
			std::cout << std::endl << "You don't have money anymore! Out of the CASINO!" << std::endl << std::endl;
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
	int as(0);
	for( int i = 0 ; i < l.count() ; ++i ) {
		if(l[i] == 1)
			as += 10;
		sum += qMin(l[i], 10);
	}

	while(as != 0 && sum <= 11)
	{
		as -=10;
		sum += 10;
	}

	return sum;
}

int getCard(const QList<int>& listing, const QList<int>& listing2)
{
	int res;
	if( qrand() % 4 == 0 )
		res = qrand() % 3 + 12;
	else
		res = qrand() % 10 + 1;

	int count(0);
	for(int i = 0; i < listing.count();++i)
		if(listing[i] == res)
			++count;
	for(int i = 0; i < listing2.count();++i)
		if(listing2[i] == res)
			++count;
	if(count < 4)
		return res;
	else
		return getCard(listing, listing2);
}

std::string cardValueToStr(int value) {
	switch (value)
	{
	case 1: return "Ace";
	case 12: return "Jack";
	case 13: return "Queen";
	case 14: return "King";
	default: {
		char v[2];
		_itoa(value, v, 10);
		return std::string(v);
		}
	}

}

void blackJack() {
	std::cout <<  std::endl;
		std::cout << "******   **        ***      ****   **    **    **    ***      ****   **    **" << std::endl;
		std::cout << "*******  **        ***     ******  **   **     **    ***     ******  **   ** " << std::endl;
		std::cout << "**   **  **        ***     **  *** **  **      **    ***     **  *** **  **  " << std::endl;
		std::cout << "**   **  **       ** **   **    *  **  **      **   ** **   **    *  **  **  " << std::endl;
		std::cout << "******   **       ** **   **       ** **       **   ** **   **       ** **   " << std::endl;
		std::cout << "******   **       ** **   **       ******      **   ** **   **       ******  " << std::endl;
		std::cout << "**   **  **      **   **  **       *** **      **  **   **  **       *** **  " << std::endl;
		std::cout << "**   **  **      *******  **    *  **   ** **  **  *******  **    *  **   ** " << std::endl;
		std::cout << "**   **  **      *******   **  *** **   ** **  **  *******   **  *** **   ** " << std::endl;
		std::cout << "*******  *********     **  ******  **    ******** **     **  ******  **    **" << std::endl;
		std::cout << "******   *********     **   ****   **    ** ****  **     **   ****   **    **" << std::endl;
	std::cout <<  std::endl;
}


void casino() {
	std::cout <<  std::endl;
	std::cout << "       _,,,_,                                                               " << std::endl;
	std::cout << "    x0QN#BNQ00#Np         ,#0                                      _        " << std::endl;
	std::cout << "  /#D#D&^^'~^NM0`       g#M0A'                                   xNM1       " << std::endl;
	std::cout << " M#0Q8         `      ^^~`                                       M#&c       " << std::endl;
	std::cout << "##M0P                  _qq#pq       ,ggQM*g,     ppam ,mpak_   wN0B0mggp    " << std::endl;
	std::cout << "NQN#                 m&&@0WMg#q    R#D0W0KM0#    ###0QQ&#000x  M00##&00M    " << std::endl;
	std::cout << "&Q0$      *mqxmqa   ;M#0    NANL         `BN&I   F0D00`  0DN#   |K00        " << std::endl;
	std::cout << "M000      4K&QM0#   0QM&_,_,_000        ,g#&&T   #0&#     N#Q1  ]#MM1       " << std::endl;
	std::cout << "0N00,        MR00   QN00$0*A#&M8    ,WM00M0#&1   4&00     KQ#    0MN        " << std::endl;
	std::cout << " Qb0#z       00N0   0&0&           ##K&   MM0f   &AQ&     0Q0   ]g&05       " << std::endl;
	std::cout << "  00QM0m__,_p0&00   ^0QQg     _q  ]NK05  _8M0q_  &p0Q     NB#    0#&&_ ,    " << std::endl;
	std::cout << "   ~#&000#Q&0N00~    ^NQQ0#gMQ#0   #&&QMQ&00000  B&00     N00$   D&NM0&0Y   " << std::endl;
	std::cout << "      '~*~MM~^         ^^M*7^^      ~N7~  ~~~^   ^^~~     ~~'     ~**+^~    " << std::endl;
	std::cout << "                                                               _ ____ _,    " << std::endl;
	std::cout << "                                        ,,_,__pqmnpgqpQ0B#NNN00M0##B0##P    " << std::endl;
	std::cout << "                           ,,_qgmpWD#0M#@#*M*~^^~~^~^~^^`                   " << std::endl;
	std::cout << "              _,_paguNM0#*M^^~~~`                                           " << std::endl;
	std::cout << "      ,ggmNMFP~~'^^              _,xr++x,            _zr                    " << std::endl;
	std::cout << "     `                         w#F     `             `                      " << std::endl;
	std::cout << "                              xQ^      _e~'4#  xf    gf  m& a#&  a*~@z      " << std::endl;
	std::cout << "                              N8      m~  ,#!  N0#, *#  MBA` 0' x~  j&      " << std::endl;
	std::cout << "                              #Q     O0 _*B& m   &8 0_w #F  aM,/D  _#`      " << std::endl;
	std::cout << "                               #&,   `~^  ~~ `~ ~~  ^`  ^   ~'   '+^        " << std::endl;
	std::cout << "                                 ~~'*+^                                     " << std::endl;                          
	std::cout <<  std::endl;
}

void getout() {
	system("CLS");
	std::cout <<  std::endl;
	std::cout << "                   _,pmNM0MQqgpq@              " << std::endl;                                 
	std::cout << "               ,__#M~     _pNMPM0Mg_             " << std::endl;                               
	std::cout << "               ~0MMg  M&m00Zpggp,_ZM0p,            " << std::endl;                             
	std::cout << "               #' _#M  ~`4000````~_BM^~#g         " << std::endl;                              
	std::cout << "              0N0F~Bf     `7N000MMM'    ~0g      " << std::endl;                               
	std::cout << "             #&0M_mF                      ^Q,    " << std::endl;                               
	std::cout << "            j'MMP~   __gpgxawmpqg__         4g   " << std::endl;                               
	std::cout << "           ,X     _pMM~`__       ~~']f       ~6  " << std::endl;                               
	std::cout << "           0     g#`qpM0M~~         ~         M,  " << std::endl;                              
	std::cout << "           #    0~ M~`                         #  " << std::endl;                              
	std::cout << "           &   pX                              #  " << std::endl;                              
	std::cout << "           #   ~                               #  " << std::endl;                              
	std::cout << "           #                                   &   " << std::endl;                             
	std::cout << "           Q                                  #^   " << std::endl;                             
	std::cout << "           ]&                                jP    " << std::endl;                             
	std::cout << "            #                               g@     " << std::endl;                             
	std::cout << "            ]&                            _0'      " << std::endl;                             
	std::cout << "             4p                         ,g@                      _ppgpgg&m***=" << std::endl; 
	std::cout << "              46              _ppggpggqN0&pppggpppgg0N00NN00N000MM0N00M       " << std::endl;  
	std::cout << "               ~&,            #&~^`,0M~```                       ^0000F    " << std::endl;     
	std::cout << "                `M&g_        j0Lg0M~                                ` " << std::endl;          
	std::cout << "                   ^7MMNMN0MN00F^                      " << std::endl;                         
	std::cout << "                            gP0                       " << std::endl;                          
	std::cout << "                           qP 0                       " << std::endl;                          
	std::cout << "                          ##  #                       " << std::endl;                          
	std::cout << "                        _0F  ]#                       " << std::endl;                          
	std::cout << "                       p0^   #'                      " << std::endl;                           
	std::cout << "                      #@     0                      " << std::endl;                            
	std::cout << "                    y#!     ]0                       " << std::endl;                           
	std::cout << "                   pM`      0T                     " << std::endl;                             
	std::cout << "                _g0P        0                       " << std::endl;                            
	std::cout << "             _g00M         j@                   " << std::endl;                                
	std::cout << "        _pg00M~            0                 " << std::endl;                                   
	std::cout << "      g0M~`               j#                  " << std::endl;                                  
	std::cout << "    ,#V                   Mf                 " << std::endl;                                   
	std::cout << "   _0M&                  ]#                  " << std::endl;                                   
	std::cout << "   0M 4g                 0!                  " << std::endl;                                   
	std::cout << "  ]X]L 0                y0                    " << std::endl;                                  
	std::cout << "  #  #                  0f                    " << std::endl;                                  
	std::cout << "                        @                     " << std::endl;  
	std::cout <<  std::endl;
}

void sexy() {
	system("CLS");
	std::cout <<  std::endl;
	std::cout << "                      _.`'''`.`.`-.						" << std::endl;
	std::cout << "                    ,'`,`.`,`'--...;." << std::endl;
	std::cout << "                   /`.`, ,'` `-'-._ ``." << std::endl;
	std::cout << "                 ,'` ,;-'  _ ``    ._ `\\" << std::endl;
	std::cout << "                /` ,;'  ,'', _  ``  `  `\\" << std::endl;
	std::cout << "              _/`,'' _,' ,'   `.` `  ` `/" << std::endl;
	std::cout << "              \\_' _,   ,'      | f\\ ` ` |" << std::endl;
	std::cout << "               `.; ```/         \\| `.`   |" << std::endl;
	std::cout << "                '.`--'\\  .'`    ;|  |` `/" << std::endl;
	std::cout << "                  `.  `.  <6    <6   /__/'" << std::endl;
	std::cout << "                    `- |      (    /-''" << std::endl;
	std::cout << "                       ;\\   ._.  .`" << std::endl;
	std::cout << "                  _.--'  `.    ,|--.._" << std::endl;
	std::cout << "              ,--' ._ ..__ `''` |   :;`-." << std::endl;
	std::cout << "             /.           `''   !    :;  ;" << std::endl;
	std::cout << "            /:                        :; |" << std::endl;
	std::cout << "           /:.                        :; |" << std::endl;
	std::cout << "          /:.                          :;|" << std::endl;
	std::cout << "         /:.      ,____        `;.      ;;." << std::endl;
	std::cout << "        /_.,,,;;;;;;;;;;;;;;::-. \\:.  ,;;;;\\ " << std::endl;
	std::cout << "       /:```''` /;;;;;;;;;;::::::;\\;,;;;;-' ;" << std::endl;
		std::cout << "      /:.     ;/;;;;;;;;:::-''-'.-';.'.-'.-.;" << std::endl;
	std::cout << "     /:.     /  \\;;;;:-'-'.-'.-'.-';.'.-'../" << std::endl;
	std::cout << "    ;:.     /    \\;;:''.-'.-'.-'.-/.-'.-';'" << std::endl;
	std::cout << "    |:.    /      \\;:.'.-'.-'.-.-''.-'..|" << std::endl;
	std::cout << "    |:.   ;        \\::..-'.-'.-'.-'.-'..;" << std::endl;
	std::cout << "    |:.   |         \\::.-'.-'.-'.-'.-'..;" << std::endl;
	std::cout << "    ::.   ;          \\::.'.-'.-'.-'.-'.-.;" << std::endl;
	std::cout << "     \\:.  `\\          ;::..-'.-'.-'.-'.-.|" << std::endl;
	std::cout << "      \\:.  `\\         |::..-'.-'.-'.-'.-.;" << std::endl;
	std::cout << "       \\:.  `\\        |::..-'.-'.-'.-'.-.|" << std::endl;
	std::cout << "        \\:.  `\\       ;::..-'.-'.-'.-'.-.;" << std::endl;
	std::cout << "         \\:.  '\\     /::.'.-'.-'.-'.-'.-'.;" << std::endl;
	std::cout << "          \\:.  '\\   /::.-'.-'.-'.-'.-'.-'.|" << std::endl;
	std::cout << "           \\:.  `\\ /:::.-'.-'.-'.-'.-'.-'.;\\" << std::endl;
	std::cout << "            \\:.  `;:::..-'.-'.-'.-'.-'.-'.|.;" << std::endl;
	std::cout << "             ;.    \\:.'.-'.-'.-'.-'.-'.-'.:. ;" << std::endl;
	std::cout << "             \\:.  `_`):.-'.-'.-'.-'.-'.-'.|. |" << std::endl;
	std::cout << "             |:. `__):..-'.-'.-'.-'.-'.-'.'.. \\" << std::endl;
	std::cout << "              \\:.`__):__-'.-'.-'.-'.-'.-'..|.\\ |" << std::endl;
	std::cout << "               '-._):.  `.._'.-'.-'.-'.-'..\\ \\!|" << std::endl;
	std::cout << "                   |:.      `''''';;-------;!!/" << std::endl;
	std::cout << "                   `:.            \\:.     | `'" << std::endl;
	std::cout << "                    \\:.            \\:.    |" << std::endl;
	std::cout << "                     \\:.            \\:.   |" << std::endl;
	std::cout << "                      \\:.            \\:. |" << std::endl;
	std::cout << "                       \\:.            \\:.|" << std::endl;                                                                      
	std::cout <<  std::endl;
}