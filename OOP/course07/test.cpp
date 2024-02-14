#include "Wallet.h"
#include <iostream>

int main()
{
    // test1
    {
        Wallet myWallet{};
        std::cout << "Inserting 10 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 100);
        std::cout << "Wallet contents " << myWallet << std::endl;
    }

    // test1
    {
        Wallet myWallet{};
        std::cout << "Inserting 10 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 100);
        std::cout << "Wallet contents " << myWallet << std::endl;
    }

    // test1
    {
        Wallet myWallet{};
        std::cout << "Inserting 10 BTC" << std::endl;
        myWallet.insertCurrency("BTC", 100);
        std::cout << "Wallet contents " << myWallet << std::endl;
    }

    return 0;
}