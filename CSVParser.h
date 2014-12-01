/*
 * CSVParser.h
 *
 *  Created on: Nov 30, 2014
 *      Author: csage
 */

#ifndef CSVPARSER_H_
#define CSVPARSER_H_
#include <vector>
#include <string>

using namespace std;
class CSVParser {
public:
	CSVParser();
	void userPrompt();
	vector< vector<string> > parse(string);
	void print(vector <vector<string> >);
};


#endif /* CSVPARSER_H_ */
