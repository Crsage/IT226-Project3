/*
 * CSVParser.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: csage
 */


#include "CSVParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
using std::cout;
using std::cin;
using std::endl;



static std::vector< std::vector< std::string> > parse(std::string &filename)
{
	std::vector< std::vector< std::string > > retVect;
	std::vector< std::string > row;
	std::stringstream sstream;
	bool inside = false;
	std::ifstream ifs(filename.c_str());

	if(ifs.fail())
	{
		cout << "File Not Found" << endl;
	}
	while(ifs.good())
	{
		char curr = ifs.get();
		if(!inside && curr=='"')
		{
			inside = true;
		}
		else if(inside && curr=='"')
		{
			if(ifs.peek() == '"')
			{
				sstream << ifs.get();
			}
			else
			{
				inside = false;
			}
		}
		else if(!inside && curr==',')
		{
			row.push_back(sstream.str());
			sstream.str("");
		}
		else if(!inside && curr=='\n')
		{
			row.push_back(sstream.str());
			sstream.str("");
			retVect.push_back(row);//the problem
			row.clear();
		}
		else
		{
			sstream << curr;
		}
	}
	ifs.close();
	return retVect;

}

static void print(std::vector < std::vector< std::string> > retVect)
{
	for(std::vector< std::vector< std::string > >::size_type i = 0; i<retVect.size(); i++)
	{
		for(std::vector<std::string>::size_type j = 0; j<retVect[i].size(); j++)
		{
			cout <<  retVect[i][j] << " ";
		}
		cout << "\n";
	}
}

static void userPrompt()
{
	while(true)
	{
		std::string filename;
		cout << "Choose File to Parse and Print:\n"
				"1. 467-fall-2002.csv\n"
				"2. 380-spring-2002.csv\n"
				"3. 437-fall-2003.csv\n"
				"4. Quit";
		std::string value;
		cin >> value;
		if(value == "1")
		{
			filename = "467-fall-2002.csv";
		}
		else if(value == "2")
		{
			filename = "380-spring-2002.csv";
		}
		else if (value == "3")
		{
			filename = "437-fall-2003.csv";
		}
		else if(value == "4")
		{
			break;
		}
		else
		{
			cout << "Invalid Choice";
		}
		std::vector< std::vector< std::string > > vect = parse(filename);
		print(vect);
	}
}