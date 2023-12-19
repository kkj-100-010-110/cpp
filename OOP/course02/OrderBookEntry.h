#pragma once

#include <string>

enum class OrderBookType{bid, ask};
class OrderBookEntry
{
public:
	OrderBookEntry();
	OrderBookEntry(double _price);
	OrderBookEntry(double _price,
				   double _amount,
				   std::string _timestamp,
				   std::string _product,
				   OrderBookType _orderType);

	double getPrice();
	
	double price;
	double amount;
	std::string timestamp;
	std::string product;
	OrderBookType orderType;
};