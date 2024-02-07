#include "Population.h"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(const std::string& csvLine, char separator);

int main()
{
	std::vector<Population> dataSet;
	std::string csvFilename{"world_population_data.csv"};
	std::ifstream csvFile{"world_population_data.csv"};
	if (csvFile.is_open()) {
		std::cout << "Opened file " << csvFilename << std::endl;
	} else {
		std::cout << "Problem opening file " << csvFilename << std::endl;
	}
	std::string line;
	while (std::getline(csvFile, line)) {
		std::vector<std::string> tokens = tokenise(line, ',');
		if (tokens.size() != 17) continue;
		try {
			int rank = std::stoi(tokens[0]);
			std::string cca3 = tokens[1];
			std::string country = tokens[2];
			std::string continent = tokens[3];
			unsigned long population_2023 = std::stoul(tokens[4]);
			unsigned long population_2022 = std::stoul(tokens[5]);
			unsigned long population_2020 = std::stoul(tokens[5]);
			unsigned long population_2015 = std::stoul(tokens[6]);
			unsigned long population_2010 = std::stoul(tokens[7]);
			unsigned long population_2000 = std::stoul(tokens[8]);
			unsigned long population_1990 = std::stoul(tokens[9]);
			unsigned long population_1980 = std::stoul(tokens[10]);
			unsigned long population_1970 = std::stoul(tokens[11]);
			unsigned long area = std::stoul(tokens[12]);
			int density = std::stoi(tokens[13]);
			float growth_rate = std::stof(tokens[14]);
			float world_percentage = std::stof(tokens[15]);
			dataSet.push_back(Population(rank, cca3, country, continent , population_2023, population_2022
										, population_2020, population_2015, population_2010
										, population_2000, population_1990, population_1980, population_1970
										, area, density , growth_rate, world_percentage));
		} catch (const std::exception& e) { // exception handling
			continue;
		}
	}

	// print Top 20 world population
	std::cout << "Top 20 World Population." << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << "Rank: ";
		std::cout.width(3);
		std::cout << dataSet[i].getRank();
		std::cout << " Country: " << dataSet[i].getCountry() << "(" << dataSet[i].getCca3() << ")" << std::endl;
	}
	while (true) {
		std::cout << "Enter a country or q to quit: ";
		std::string c;
		std::getline(std::cin, c);
		if (c == "q") break;
		for (auto& e : dataSet) {
			if (e.getCountry() == c)
				e.print();
		}
	}

	csvFile.close();
	return 0;
}

std::vector<std::string> tokenise(const std::string& csvLine, char separator)
{
	std::vector<std::string> tokens;
	signed int start, end;
	std::string token;
	start = csvLine.find_first_not_of(separator, 0);
	do {
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || end == start) break;
		if (end >= 0) token = csvLine.substr(start, end - start);
		else token = csvLine.substr(start, csvLine.length() - start);
		tokens.push_back(token);
		start = end + 1;
	} while (end != std::string::npos);

	return tokens;
}