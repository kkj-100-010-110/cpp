#pragma once

#include "OrderBookEntry.h"

#include <iostream>
#include <string>
#include <map>

class Wallet
{
public:
    Wallet();
    /**
     * @brief insert currency to the wallet
     * 
     * @param type 
     * @param amount 
     */
    void insertCurrency(std::string type, double amount);
    /**
     * @brief remove currency from the wallet
     * 
     * @param type 
     * @param amount 
     * @return true 
     * @return false 
     */
    bool removeCurrency(std::string type, double amount);
    /**
     * @brief check if the wallet contains this much currency or more
     * 
     * @param type 
     * @param amount 
     * @return true 
     * @return false 
     */
    bool containsCurrency(std::string type, double amount);
    /**
     * @brief checks if the wallet can cope with this ask or bid
     * 
     * @param order 
     * @return true 
     * @return false 
     */
    bool canFulfillOrder(const OrderBookEntry& order);
    /**
     * @brief generate a string representation of the wallet
     * 
     * @return std::string 
     */
    std::string toString();

    friend std::ostream& operator << (std::ostream& out, Wallet& wallet);

private:
    std::map<std::string, double> currencies;
};
