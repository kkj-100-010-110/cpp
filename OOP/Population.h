#ifndef __POPULATION_H__
#define __POPULATION_H__

#include <string>
#include <iostream>

class Population
{
private:
    int rank;
    std::string cca3;
    std::string country;
    std::string continent;
    unsigned long population_2023;
    unsigned long population_2022;
    unsigned long population_2020;
    unsigned long population_2015;
    unsigned long population_2010;
    unsigned long population_2000;
    unsigned long population_1990;
    unsigned long population_1980;
    unsigned long population_1970;
    unsigned long area;
    int density;
    float growth_rate;
    float world_percentage;
public:
    Population(int rank, std::string cca3, std::string country, std::string continent,
               unsigned long population_2023, unsigned long population_2022, unsigned long population_2020,
               unsigned long population_2015, unsigned long population_2010,
               unsigned long population_2000, unsigned long population_1990,
               unsigned long population_1980, unsigned long population_1970,
               unsigned long area, int density, float growth_rate, float world_percentage);
    int getRank() const { return rank; }
    std::string getCca3() const { return cca3; }
    std::string getCountry() const { return country; }
    std::string getContinent() const { return continent; }
    unsigned long getPopulation2023() const { return population_2023; }
    unsigned long getPopulation2022() const { return population_2022; }
    unsigned long getPopulation2020() const { return population_2020; }
    unsigned long getPopulation2015() const { return population_2015; }
    unsigned long getPopulation2010() const { return population_2010; }
    unsigned long getPopulation2000() const { return population_2000; }
    unsigned long getPopulation1990() const { return population_1990; }
    unsigned long getPopulation1980() const { return population_1980; }
    unsigned long getPopulation1970() const { return population_1970; }
    int getArea() const { return area; }
    float getGrowthRate() const { return growth_rate; }
    float getWorldPercentage() const { return world_percentage; }

    void print();
};

#endif //__POPULATION_H__