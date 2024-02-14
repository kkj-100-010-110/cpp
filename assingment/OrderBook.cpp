#include "OrderBook.h"
#include <map>
#include <iostream>

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

/** return vector of all know products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;

    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }
    // now flatten the map to a vector of strings
    for (auto const& e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}

/** return vector of Orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    // if (orders_sub.size() == 0) return nullptr;

    return orders_sub;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string nextTimestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            nextTimestamp = e.timestamp;
            break;
        }
    }
    if (nextTimestamp == "")
    {
        nextTimestamp = orders[0].timestamp;
    }
    return nextTimestamp;
}

/** return the price according to the sent filters */
double OrderBook::getCurrentPrice(OrderBookType type, std::string product, std::string timestamp)
{
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp)
            return e.price;
    }
    return 0;
}

/** return the previous timestamp */
std::string OrderBook::getPreviousTime(std::string timestamp)
{
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].timestamp == timestamp)
        {
            return i != 0 ? orders[i-1].timestamp : orders[i].timestamp;
        }
    }
    return timestamp;
}

/** return the change rate
* (New Price - Old Price)/Old Price and then multiply that number by 100
**/
double OrderBook::getChange(double newPrice, double oldPrice)
{
    return (newPrice - oldPrice) / oldPrice * 100;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max) max = e.price;
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min) min = e.price;
    }
    return min;
}