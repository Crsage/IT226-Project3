#include <iostream>
#include <fstream>
#include <string>
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

cout << "What option would you like to do:\n To add data enter 'a' or 'A'\n To Save data enter 's' or 'S'\n To exit enter 'e' or 'E'" << endl;
cin >> x;
bool flag = true;
while(flag == true)
{
	ofstream exportFile;
	CSVParser a;
	vector< vector<string> > vect;
	switch(x) 
	{

		case 'a':
		case 'A':
			cout << "Which file would you like to extract data from?" << endl;
			cin >> file;
			
			cout << "Enter the semester and year" << endl;
			cin >>semester;
			cin >> year;
			
			cout << "Enter the course number" << endl;
			cin >> courseNo;
		
			//read file and add to repository
			vect = a.parse(file);
			a.print(vect);
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
