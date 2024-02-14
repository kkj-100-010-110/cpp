#include "MerkelMain.h"
#include "CSVReader.h"
#include <iomanip>

MerkelMain::MerkelMain()
{
	menu[1] = &MerkelMain::printHelp;
	menu[2] = &MerkelMain::printMarketStats;
	menu[3] = &MerkelMain::enterOffer;
	menu[4] = &MerkelMain::enterBid;
	menu[5] = &MerkelMain::printWallet;
	menu[6] = &MerkelMain::gotoNextTimeframe;
	menu[7] = &MerkelMain::printProductPriceChange;
}

void MerkelMain::init()
{
    int input;
	currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        // processUserOption(input);
        processUserOptionMap(input);
    }
}

void MerkelMain::printMenu()
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
		// 7 change
		std::cout << "7: Price Change " << std::endl;

		std::cout << "============== " << std::endl;

		std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
	std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
	for (std::string const& p : orderBook.getKnownProducts())
	{
		std::cout << "Product: " << p << std::endl;
		std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
		std::cout << "Asks seen: " << entries.size() << std::endl;
		std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
		std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
	}

	// unsigned int bids = 0;
	// unsigned int asks = 0;
	// for (OrderBookEntry& e : orders)
	// {
	// 	if (e.orderType == OrderBookType::ask) {
	// 		asks++;
	// 	} else if (e.orderType == OrderBookType::bid) {
	// 		bids++;
	// 	}
	// }
	// std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
	// std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}

void MerkelMain::enterOffer()
{
	std::cout << "Make an offer - enter the amount " << std::endl;
}

void MerkelMain::enterBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
	std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
	std::cout << "Going to next time frame. " << std::endl;
	currentTime = orderBook.getNextTime(currentTime);
}

void MerkelMain::printProductPriceChange()
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "Product" << std::setw(6) << "TYPE" << std::setw(15) << "Price" << std::setw(10) << "Change" << std::endl;
	for (std::string const& p : orderBook.getKnownProducts())
	{
		std::cout << std::setw(10) << p;
		double newPrice = orderBook.getCurrentPrice(OrderBookType::ask, p, currentTime);
		double oldPrice = orderBook.getCurrentPrice(OrderBookType::ask, p, orderBook.getPreviousTime(currentTime));
		std::cout << std::setw(6) << "ASK";
		std::cout << std::setw(15) << newPrice;
		std::cout << std::setw(10);
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << OrderBook::getChange(newPrice, oldPrice) << "%";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::setw(10) << "Product" << std::setw(6) << "TYPE" << std::setw(15) << "Price" << std::setw(10) << "Change" << std::endl;
	for (std::string const& p : orderBook.getKnownProducts())
	{
		std::cout << std::setw(10) << p;
		double newPrice = orderBook.getCurrentPrice(OrderBookType::bid, p, currentTime);
		double oldPrice = orderBook.getCurrentPrice(OrderBookType::bid, p, orderBook.getPreviousTime(currentTime));
		std::cout << std::setw(6) << "BID";
		std::cout << std::setw(15) << newPrice;
		std::cout << std::setw(10);
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << OrderBook::getChange(newPrice, oldPrice) << "%";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int MerkelMain::getUserOption()
{
		int userOption;

		std::cout << "Type in 1-7 " << std::endl;
		std::cin >> userOption;
		std::cout << "You chose: " << userOption << std::endl;

		return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
		if (userOption == 0) // bad input
		{
			std::cout << "Invalid choice. Choose 1-6" << std::endl;
		}
		if (userOption == 1) // bad input
		{
			printHelp();
		}
		if (userOption == 2) // bad input
		{
			printMarketStats();
		}
		if (userOption == 3) // bad input
		{
			enterOffer();
		}
		if (userOption == 4) // bad input
		{
			enterBid();
		}
		if (userOption == 5) // bad input
		{
			printWallet();
		}
		if (userOption == 6) // bad input
		{
			gotoNextTimeframe();
		}
}

void MerkelMain::processUserOptionMap(int userOption)
{
		if (userOption == 0 || userOption > 7) // bad input
		{
			std::cout << "Invalid choice. Choose 1-7" << std::endl;
		}
		else
		{
			(this->*menu[userOption])();
		}
}