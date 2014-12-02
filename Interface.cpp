#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CSVParser.h"
using namespace std;

int main()
{

string file;
string outFilename;
string semester;
string studentID;
int year = 0;
string courseNo;
char x;
ofstream exportFile;
CSVParser a;
vector< vector<string> > vect;
vector<string> header;
map<string,vector<string> > repository;
map<string,vector<string> > headersMap;
string filename;
string value;

cout << "What option would you like to do:\n To add data enter 'a' or 'A'\n To Save data enter 's' or 'S'\n To exit enter 'e' or 'E'" << endl;
cin >> x;
bool flag = true;
while(flag == true)
{
	switch(x) 
	{

		case 'a':
		case 'A':
			cout << "Which file would you like to extract data from?" << endl;
			cout << //"Choose File to Parse and Print:\n"
					"1. 467-fall-2002.csv\n"
					"2. 380-spring-2002.csv\n"
					"3. 437-fall-2003.csv\n"
					"4. Quit";

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
			//std::vector< std::vector< std::string > > vect = parse(filename);
			//cin >> file;
			
			cout << "Enter the semester and year" << endl;
			cin >>semester;
			cin >> year;
			
			cout << "Enter the course number" << endl;
			cin >> courseNo;
		
			//read file and add to repository
			vect = a.parse(filename);
			header = a.getHeaders(vect);
			headersMap.insert(pair<string,vector<string> > (courseNo,header));
			//vect = a.removeHeaders(vect);
			cout << "Number of Students in Repository: " << repository.size() << endl;
			cout << "Number of Students to be added to Repository: "
					<< vect.size()-1 << endl;
			repository = a.addToRepo(vect,repository);
			cout << "New Repository Size: " << repository.size() << endl;


			//a.print(vect);
			//cout << "Reads the file(if it exists) and adds to our already exisiting repository." << endl;
			//Print number of students read and how many there were.
			//cout << "Prints the number of students read from file and also how many students there were." << endl;
			
			cout << "Enter 'a' to add data, 's' to save a students data, or 'e' to exit" << endl;
			cin >> x;
			break;
		
		case 's':
		case 'S':
			cout << "Enter student ID" << endl;
			cin >> studentID;
			
			cout << "Enter file to export to" << endl;
			cin >> outFilename;
			outFilename = outFilename + ".csv";
			cout << "Students data will be exported to " << outFilename << endl;
			
			cout << "Enter 'a' to add data, 's' to save a students data, or 'e' to exit." << endl;
			cin >> x;
			break;
		case 'e':
		case 'E':
			cout << "Exiting program." << endl;
			flag = false;
			break;
		default:
			cout << "Not a valid entry try again" << endl;
			cin >> x;
	}
	
}
return 0;
	
}
