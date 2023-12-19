#include <iostream>
#include <map>

void printMenu();
int getUserOption();
//void processUserOption(int userOption);
void processUserOption(int userOption, std::map<int, void(*)()> &menu);
void printHelp();
void printMarketStats();
void enterOffer();
void enterBid();
void printWallet();
void gotoNextTimeframe();

int main()
{
	std::map<int, void(*)()> menu;
	menu[1] = printHelp;
	menu[2] = printMarketStats;
	menu[3] = enterOffer;
	menu[4] = enterBid;
	menu[5] = printWallet;
	menu[6] = gotoNextTimeframe;

	while (true)
	{
		printMenu();
		int userOption = getUserOption();
		processUserOption(userOption, menu);
	}

	return 0;
}

void printMenu()
{
		// 1 print help
		std::cout << "1: Print help " << std::endl;
		// 2 print exchange stats
		std::cout << "2: Print exchange stats " << std::endl;
		// 3 make an offer --> what you've got to sell
		std::cout << "3: Make an offer " << std::endl;
		// 4 make a bid --> what you'd like to buy
		std::cout << "4: Make a bid " << std::endl;
		// 5 print wallet
		std::cout << "5: Print wallet " << std::endl;
		// 6 continue
		std::cout << "6: Continue " << std::endl;

		std::cout << "============== " << std::endl;
}

void printHelp()
{
	std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void printMarketStats()
{
	std::cout << "Market looks good" << std::endl;
}

void enterOffer()
{
	std::cout << "Make an offer - enter the amount " << std::endl;
}

void enterBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
	std::cout << "Your wallet is empty. " << std::endl;
}

void gotoNextTimeframe()
{
	std::cout << "Going to next time frame. " << std::endl;
}

int getUserOption()
{
		int userOption;

		std::cout << "Type in 1-6 " << std::endl;
		std::cin >> userOption;
		std::cout << "You chose: " << userOption << std::endl;

		return userOption;
}

void processUserOption(int userOption, std::map<int, void(*)()> &menu)
{
		if (userOption == 0 || userOption > 6) // bad input
		{
			std::cout << "Invalid choice. Choose 1-6" << std::endl;
		}
		else
		{
			menu[userOption]();
		}
}

// void processUserOption(int userOption)
// {
// 		if (userOption == 0) // bad input
// 		{
// 			std::cout << "Invalid choice. Choose 1-6" << std::endl;
// 		}
// 		if (userOption == 1) // bad input
// 		{
// 			printHelp();
// 		}
// 		if (userOption == 2) // bad input
// 		{
// 			printMarketStats();
// 		}
// 		if (userOption == 3) // bad input
// 		{
// 			enterOffer();
// 		}
// 		if (userOption == 4) // bad input
// 		{
// 			enterBid();
// 		}
// 		if (userOption == 5) // bad input
// 		{
// 			printWallet();
// 		}
// 		if (userOption == 6) // bad input
// 		{
// 			gotoNextTimeframe();
// 		}
// }