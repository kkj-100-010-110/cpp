#pragma once

#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

#include <vector>
#include <map>
#include <iostream>

class MerkelMain
{
public:
    MerkelMain();
    /** Call this to start the sim */
    void init();

private:
    void loadOrderBook();
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void processUserOption(int userOption);
    void processUserOptionMap(int userOption);

private:
    std::string currentTime;
    OrderBook orderBook{"20200317.csv"};
    // OrderBook orderBook{"test.csv"};
    std::vector<OrderBookEntry> orders;
    std::map<int, void(MerkelMain::*)()> menu;
    Wallet wallet;
};