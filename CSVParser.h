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
class CSVParser {
public:
	static void userPrompt();
	static std::vector< std::vector< std::string> > parse(std::string &filename);
	static void print(std::vector < std::vector< std::string> > retVect);
};


#endif /* CSVPARSER_H_ */
