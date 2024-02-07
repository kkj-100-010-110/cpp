#pragma once

#include "OrderBookEntry.h"
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
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void processUserOption(int userOption);
    void processUserOptionMap(int userOption);

private:
    std::vector<OrderBookEntry> orders;
    std::map<int, void(MerkelMain::*)()> menu;
};