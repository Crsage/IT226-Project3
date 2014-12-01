#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

string file;
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
	
	switch(x) 
	{

		case 'a':
			cout << "Which file would you like to add to?" << endl;
			cin >> file;
			//outFile.open (file);
			cout << "Enter the semester and year" << endl;
			cin >>semester;
			cin >> year;
			cout << "Enter the course number" << endl;
			cin >> courseNo;
			//outFile.close();
		
			//read file and add to repository
		
			//Print number of students read and how many there were.
			cout << "You can enter a, s, or e" << endl;
			cin >> x;
			break;
		
		case 's':
			cout << "Enter student ID" << endl;
			cin >> studentID;
			cout << "Enter file to export to" << endl;
			cout << "You can enter a, s, or e" << endl;
			cin >> x;
			break;
		case 'e':
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
