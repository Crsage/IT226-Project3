/*
 * CSVParser.h
 *
 *  Created on: Nov 30, 2014
 *      Author: csage
 */

#ifndef CSVPARSER_H_
#define CSVPARSER_H_
#include <vector>
#include <map>
#include <string>

using namespace std;
class CSVParser {
public:
	CSVParser();
	void userPrompt();
	vector< vector<string> > parse(string);
	void print(vector <vector<string> >);
	map<string,vector<string> > addToRepo(const vector<vector<string> >& vect,map<string,vector<string> >& repo);
	vector<string> getHeaders(const vector< vector<string> >& vect);
	vector<vector<string> > removeHeaders(vector<vector<string> >);
};


#endif /* CSVPARSER_H_ */
