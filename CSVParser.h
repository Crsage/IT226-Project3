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
	vector< vector<string> > parse(string);
	void print(vector <vector<string> >);
	vector<string> getHeaders(const vector< vector<string> >& vect);
	vector<string> getStudentAt(int index, const vector< vector<string> > &vect);
	int getStudentIDIndex(const vector< vector<string> > &vect);
	void removeHeaders(vector<vector<string> > &vect);
	multimap<string,vector<string> > spliceRepoBySemester(multimap<string,vector<string> > &semesterRepo, const multimap<string,vector<string> > &repo, const string &semester);
	multimap<string,vector<string> > spliceRepoByYear(multimap<string,vector<string> > &yearRepo, const multimap<string,vector<string> > &repo, const string &year);
};
#endif /* CSVPARSER_H_ */
