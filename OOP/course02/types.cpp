#include <iostream>

int main()
{
    char c = 0;
    std::cout << "char: " << sizeof(c) << std::endl;
    signed int i = 0;
    std::cout << "signed int: " << sizeof(i) << std::endl;
    float f = 0.0f;
    std::cout << "float: " << sizeof(f) << std::endl;
    long double ld = 0.0;
    std::cout << "long double: " << sizeof(ld) << std::endl;

    return 0;
}