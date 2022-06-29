#include <iostream>
#include <string>
using namespace std;

#include "roster.h"

int main()
{
	cout << endl << "\tC867 Scripting and Programming Applications ------ C++ ------ WGU SID#001482272 ------ Jefferson Warnimont" << endl << endl << endl;

	const string studentData[] = {

	"A1,John,Smith,John1989@gm  ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jefferson,Warnimont,jwarni3@wgu.edu,35,25,15,30,SOFTWARE"

	};
	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; ++i) classRoster.parse(studentData[i]);

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A1");

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;
}