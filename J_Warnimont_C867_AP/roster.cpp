#include <iostream>
#include <string>
using namespace std;

#include "roster.h"

void Roster::parse(string studentData)
{
	int endChar = studentData.find(",");
	string studentID = studentData.substr(0, endChar);

	int beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	string firstName = studentData.substr(beginChar, endChar - beginChar);

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	string lastName = studentData.substr(beginChar, endChar - beginChar);

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	string emailAddress = studentData.substr(beginChar, endChar - beginChar);

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	int age = stoi(studentData.substr(beginChar, endChar - beginChar));

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	int daysInCourse1 = stoi(studentData.substr(beginChar, endChar - beginChar));

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	int daysInCourse2 = stoi(studentData.substr(beginChar, endChar - beginChar));

	beginChar = endChar + 1;
	endChar = studentData.find(",", beginChar);
	int daysInCourse3 = stoi(studentData.substr(beginChar, endChar - beginChar));

	beginChar = endChar + 1;
	endChar = studentData.find("\0", beginChar);
	char degree = studentData.at(54);

	DegreeProgram degreeProgram = SOFTWARE;
	if (degree == 'Y' || degree == 'I') degreeProgram = SECURITY;
	if (degree == 'E') degreeProgram = NETWORK;
	if (degree == 'A' || degree == 'T') degreeProgram = SOFTWARE;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); 
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

void Roster::printAll() {

	cout << "Displaying all students..." << endl << endl;

	for(int i = 0; i <= Roster::lastIndex; ++i)
	{
		classRosterArray[i]->print();	
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{
	cout << "Printing by requested degree..." << endl << endl;

	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (Roster::classRosterArray[i]->getProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails() 
{
	cout << "Displaying Invalid Email Addresses..." << endl << endl;

	bool invalid = false;

	for (int i = 0; i <= Roster::lastIndex; ++i) {
	
		string invalidEmail = (classRosterArray[i]->getStudentEmail());
		if (invalidEmail.find('@') == string::npos || invalidEmail.find('.') == string::npos) {
			invalid = true;
			cout << invalidEmail << endl;
		}
		else if (invalidEmail.find(' ') != string::npos) {
			invalid = true;
			cout << invalidEmail << endl;
		}
		cout << endl;
	}
} 

void Roster::printAverageDaysInCourse(string studentID)
{
	cout << "Average days to complete each course..." << endl << endl;

	for (int i = 0; i <= Roster::lastIndex; ++i) {
		cout << classRosterArray[i]->getStudentID() << ": ";
		cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
	}
	cout << endl;
}

void Roster::remove(string studentID)
{
	bool remove = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			remove = true;

			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
		if (remove) {
			cout << "Removing " << studentID << " from roster..." << endl;
		}
		else {
			cout << "Failure to remove! Student " << studentID << " not found..." << endl;
		}	
	for (int i = 0; i < numStudents -2; ++i) {
		if (classRosterArray[i]->getStudentID().at(1) > classRosterArray[i + 1]->getStudentID().at(1)) {
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[i + 1];
			classRosterArray[i + 1] = temp;
		}
	}
	cout << endl;
}
Roster::~Roster()
{
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}