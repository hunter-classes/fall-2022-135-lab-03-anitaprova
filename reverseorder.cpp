#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}

	double eastSt, eastEl, westSt, westEl;
	double west_elevation[364];
	int size = sizeof(west_elevation)/sizeof(west_elevation[0]);
	std::string date[364];

	std::string d1 = date1;
	std::string d2 = date2;

	std::string junk = "";
	getline(fin, junk);
	
	int i, start_index, end_index;
	while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) { //fills the whole array 
		fin.ignore(INT_MAX, '\n');
		west_elevation[i] = westEl;
		date[i] = date1;

		if (date1 == d1)
		{
			start_index = i;
		}

		if (date1 == d2)
		{
			end_index = i;
		}
		i++;
	}

	for (int i = end_index; i >= start_index; i--) //reverse order 
	{
		std::cout << date[i] << " " << west_elevation[i] << " ft" << std::endl;
	}	
}
