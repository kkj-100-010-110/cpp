#include "MerkelMain.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{
	menu[1] = &MerkelMain::printHelp;
	menu[2] = &MerkelMain::printMarketStats;
	menu[3] = &MerkelMain::enterAsk;
	menu[4] = &MerkelMain::enterBid;
	menu[5] = &MerkelMain::printWallet;
	menu[6] = &MerkelMain::gotoNextTimeframe;
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
		std::cout << "3: Make an ask " << std::endl;
		// 4 make a bid --> what you'd like to buy
		std::cout << "4: Make a bid " << std::endl;
		// 5 print wallet
		std::cout << "5: Print wallet " << std::endl;
		// 6 continue
		std::cout << "6: Continue " << std::endl;

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

void MerkelMain::enterAsk()
{
	std::cout << "Make an ask - enter the amount : product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
	std::string input;
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
	if (tokens.size() != 3)
	{
		std::cout << "Bad input: " << input << std::endl;
	}
	else
	{
		try
		{
			OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
			orderBook.insertOrder(obe);
		}
		catch (const std::exception& e)
		{
			std::cout << "MerkelMain::enterAsk Bad input" << std::endl;
		}
	}
	std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
	std::cout << "Make a bid - enter the amount : product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
	std::string input;
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
	if (tokens.size() != 3)
	{
		std::cout << "Bad input: " << input << std::endl;
	}
	else
	{
		try
		{
			OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
			orderBook.insertOrder(obe);
		}
		catch (const std::exception& e)
		{
			std::cout << "MerkelMain::enterBid Bad input" << std::endl;
		}
	}
	std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::printWallet()
{
	std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
	std::cout << "Going to next time frame. " << std::endl;
	std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
	std::cout << "Sales: " << sales.size() << std::endl;
	for (OrderBookEntry& sale : sales)
	{
		std::cout << "Sale amount: " << sale.price << " amount " << sale.amount << std::endl;
	}
	currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
		int userOption = 0;
		std::string line;
		std::cout << "Type in 1-6 " << std::endl;
		std::getline(std::cin, line);
		try
		{
			userOption = stoi(line);
		}
		catch(const std::exception& e)
		{
		}
		
		// std::cin >> userOption;
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
			enterAsk();
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
		if (userOption == 0 || userOption > 6) // bad input
		{
			std::cout << "Invalid choice. Choose 1-6" << std::endl;
		}
		else
		{
			(this->*menu[userOption])();
		}
}