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

	double  eastSt, eastEl, westSt, westEl;
	std::string d = date;
	std::string junk = "";
	getline(fin, junk);
	
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
		fin.ignore(INT_MAX, '\n');
		if(date == d)
		{
			break;
		}
	}

	std::cout << "East Basin Storage: " << eastSt << " billion gallons" << std::endl;
	
	return 0;
}
