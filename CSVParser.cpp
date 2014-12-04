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
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <sstream>
#include <istream>

using namespace std;

CSVParser::CSVParser()
{

}

vector< vector<string> > CSVParser::parse(string filename)
{
	vector< vector<string> >retVect;
	vector<string> row;
	stringstream sstream;
	bool inside = false;
	ifstream ifs(filename.c_str());

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
			retVect.push_back(row);
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

vector<string> CSVParser::getHeaders(const vector< vector<string> > &vect)
{
	return vect.at(0);
}

void CSVParser::removeHeaders(vector<vector<string> > &vect)
{
	vect.erase(vect.begin());
}

vector<string> CSVParser::getStudentAt(int index, const vector< vector<string> > &vect)
{
	return vect.at(index);
}

int CSVParser::getStudentIDIndex(const vector< vector<string> > &vect)
{
	string id;
	string header;
	int count = 0;
	for(unsigned i = 0; i<vect[0].size(); i++)
	{
		header = vect[0][i];
		if(header == "Student Id" || header == "User ID")
		{
			return count;	
		}
		else
			count++;
	}
}

multimap<string,vector<string> > spliceRepoBySemester(multimap<string,vector<string> > &semesterRepo, const multimap<string,vector<string> > &repo,  const string &semester)
{
	/*multimap<string, vector<string> > semRepo;
	for(std::multimap<string,int>::iterator it = repo.begin(); it != repo.end(); ++it)
	{
		vector<string> student = (*it).second;							//Broken
		semRepo.insert(pair<string,vector<string> >(semester, student ));
	}
	return semRepo;*/
	return repo;
}

multimap<string,vector<string> > spliceRepoByYear(multimap<string,vector<string> > &yearRepo, const multimap<string,vector<string> > &repo, const string &year)
{
	/*multimap<string, vector<string> > yeRepo;
	for(std::multimap<string,int>::iterator it = repo.begin(); it != repo.end(); ++it)
	{	
		vector<string> student = (*it).second;							//Broken
		yeRepo.insert(pair<string,vector<string> >(year, student));
	}
	return yeRepo;*/
	return repo;
}

void CSVParser::print(vector< vector<string> > retVect)
{
	for(unsigned i = 0; i<retVect.size(); i++)
	{
		for(unsigned j = 0; j<retVect[i].size(); j++)
		{
			cout <<  retVect[i][j] << " ";
		}
		cout << "\n";
	}
}
