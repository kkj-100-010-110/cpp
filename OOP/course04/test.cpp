#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    } while(end > 0);
    return tokens;
}

int main()
{
    // std::vector<std::string> tokens;
    // std::string s = "thing,thing1,thing2";
    // tokens = tokenise(s, ',');
    // for (const auto& e : tokens)
    //     std::cout << e << std::endl;
    std::ifstream csvFile{"20200317.csv"};

    if (csvFile.is_open())
    {
        std::cout << "File Open " << std::endl;
        csvFile.close();
    }
    else
    {
        std::cout << "Could not open " << std::endl;
    }

    return 0;
}