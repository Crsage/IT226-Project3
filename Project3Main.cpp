/*
 * Project3Main.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: csage
 */
#include "CSVParser.h"
#include "Project3Main.h"
#include <string>
#include <vector>
using namespace std;
int main()
{
	std::string filename = "380-spring-2002.csv";

	std::vector< std::vector< std::string > > vector = CSVParser::parse(filename);
	CSVParser::print(vector);
}

