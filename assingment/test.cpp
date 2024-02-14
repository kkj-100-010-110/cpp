#include "Wallet.h"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << "[Test 1]" << std::endl;
    {
        Wallet myWallet{};
        std::cout << "Inserting 100 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 100);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << "Removing 100 BTC" << std::endl;
        myWallet.removeCurrency("BTC", 10);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << std::endl;
    }
    std::cout << "[Test 2]" << std::endl;
    {
        Wallet myWallet{};
        std::cout << "Inserting 10 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 10);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << "Removing 10 BTC" << std::endl;
        myWallet.removeCurrency("BTC", 10);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << std::endl;
    }
    std::cout << "[Test 3]" << std::endl;
    {
        Wallet myWallet{};
        std::cout << "Inserting 10 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 10);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << "Removing 100 BTC" << std::endl;
        myWallet.removeCurrency("BTC", 100);
        std::cout << "Wallet contents " << myWallet << std::endl;
        std::cout << std::endl;
    }
    std::cout << "[Test 4]" << std::endl;
    {
        Wallet myWallet{};
        std::cout << "Wrong value of amount" << std::endl;
        myWallet.insertCurrency("BTC", -100);
        myWallet.removeCurrency("BTC", -10);
        std::cout << std::endl;
    }
    return 0;
}