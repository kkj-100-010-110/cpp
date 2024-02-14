#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
public:
    /** construct, reading a csv data file */
    OrderBook(std::string filename);
    /** return vector of all know products in the dataset */
    std::vector<std::string> getKnownProducts();
    /** return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
    /** return the earliest time in the orderbook */
    std::string getEarliestTime();
    /** return the next time after the sent time in the orderbook
    * if there is no next timestamp, wraps around to the start
    **/
    std::string getNextTime(std::string timestamp);

    // assignment
    /** return the price according to the sent filters */
    double getCurrentPrice(OrderBookType type, std::string product, std::string timestamp);
    /** return the previous timestamp */
    std::string getPreviousTime(std::string timestamp);

    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    static double getLowPrice(std::vector<OrderBookEntry>& orders);

    // assignment
    /** return the change rate */
    static double getChange(double currentPrice, double lastPrice);

private:
    std::vector<OrderBookEntry> orders;
};