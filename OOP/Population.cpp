#include "Population.h"

Population::Population(int rank, std::string cca3, std::string country, std::string continent,
           unsigned long population_2023, unsigned long population_2022, unsigned long population_2020,
           unsigned long population_2015, unsigned long population_2010,
           unsigned long population_2000, unsigned long population_1990,
           unsigned long population_1980, unsigned long population_1970,
           unsigned long area, int density, float growth_rate, float world_percentage)
: rank(rank)
, cca3(cca3)
, country(country)
, continent(continent)
, population_2023(population_2023)
, population_2022(population_2022)
, population_2020(population_2020)
, population_2015(population_2015)
, population_2010(population_2010)
, population_2000(population_2000)
, population_1990(population_1990)
, population_1980(population_1980)
, population_1970(population_1970)
, area(area)
, density(density)
, growth_rate(growth_rate)
, world_percentage(world_percentage)
{}

void Population::print()
{
    std::cout << "Rank: " << rank << " Country: " << country << "(" << cca3 << ")" << " Continent: " << continent << std::endl;
    std::cout << "Population of 2023: " << population_2023 << std::endl;
    std::cout << "Population of 2022: " << population_2022 << std::endl;
    std::cout << "Difference between 2022 and 2023: " << population_2023 - population_2022 << std::endl;
    std::cout << "Population of 2020: " << population_2020 << std::endl;
    std::cout << "Population of 2015: " << population_2015 << std::endl;
    std::cout << "Population of 2010: " << population_2010 << std::endl;
    std::cout << "Population of 2000: " << population_2000 << std::endl;
    std::cout << "Population of 1990: " << population_1990 << std::endl;
    std::cout << "Population of 1980: " << population_1980 << std::endl;
    std::cout << "Population of 1970: " << population_1970 << std::endl;
    std::cout << "Area: " << area << " Density: " << density << " Growth rate: "
              << growth_rate << " Percentage: " << world_percentage << std::endl;
}