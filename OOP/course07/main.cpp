#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

double computeAveragePrice(std::vector<OrderBookEntry> &entries);
double computeLowPrice(std::vector<OrderBookEntry> &entries);
double computeHighPrice(std::vector<OrderBookEntry> &entries);
double computePriceSpread(std::vector<OrderBookEntry> &entries);

int main()
{
	MerkelMain app{};
	app.init();

	return 0;
}

double computeAveragePrice(std::vector<OrderBookEntry> &entries)
{
	double sum = 0.0;
	// for (unsigned int i = 0; i < entries.size(); ++i)
	for (OrderBookEntry& e : entries)
	{
		sum += e.getPrice();
	}
	return sum / entries.size();
}
double computeLowPrice(std::vector<OrderBookEntry> &entries)
{
	double low = entries.at(0).getPrice();
	for (int i = 1; i < entries.size(); ++i)
	{
		if (low > entries[i].getPrice())
			low = entries[i].getPrice();
	}
	return low;
}
double computeHighPrice(std::vector<OrderBookEntry> &entries)
{
	double high = entries.at(0).getPrice();
	for (int i = 1; i < entries.size(); ++i)
	{
		if (high < entries[i].getPrice())
			high = entries[i].getPrice();
	}
	return high;
}
double computePriceSpread(std::vector<OrderBookEntry> &entries)
{
	return computeHighPrice(entries) - computeLowPrice(entries);
}