#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"

double get_east_storage(std::string date)
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}

	double eastSt;
	std::string d = date;
	std::string junk = "";
	getline(fin, junk);
	
	while(fin >> date >> eastSt) { 
		fin.ignore(INT_MAX, '\n');
		if(date == d)
		{
			break;
		}
	}

	std::cout << "East Basin Storage: " << eastSt << " billion gallons" << std::endl;
	
	return 0;
}

double get_min_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
		double eastSt, min;
		std::string date;
		int index = 0;

		std::string junk = "";
		getline(fin, junk);

		while(fin >> date >> eastSt) {
			fin.ignore(INT_MAX, '\n');
			if (index == 0)
			{
				min = eastSt;
				index++;
			}
			
			if (eastSt < min)
			{
				min = eastSt;
			}
		}
		
		std::cout << "Minimum storage in East basin: " << min << " billion gallons" << std::endl;
		return 0;
}

double get_max_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
		double eastSt, max;
		std::string date;
		int index = 0;

		std::string junk = "";
		getline(fin, junk);

		while(fin >> date >> eastSt) {
			fin.ignore(INT_MAX, '\n');
			if (index == 0)
			{
				max = eastSt;
				index++;
			}
			
			if (eastSt > max)
			{
				max = eastSt;
			}
		}
		
		std::cout << "Maximum storage in East basin: " << max << " billion gallons" << std::endl;
		return 0;
}

