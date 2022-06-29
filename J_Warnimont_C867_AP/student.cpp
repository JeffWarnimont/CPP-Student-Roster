#include <iostream>
#include <string>
using namespace std;

#include "student.h"

Student::Student()
{
	this->studentID = "ID";
	this->studentNameFirst = "FirstName";
	this->studentNameLast = "LastName";
	this->studentEmail = "Email";
	this->studentAge = 0;
	for (int i = 0; i < numDaysSize; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = SECURITY;
}
Student::Student(string studentID, string studentNameFirst, string studentNameLast, string studentEmail, int studentAge, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->studentNameFirst = studentNameFirst;
	this->studentNameLast = studentNameLast;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < numDaysSize; ++i) {
		this->daysInCourse[i] = days[i];
	}
	this->degreeProgram = degreeProgram;
}
Student::~Student() 
{
}
string Student::getStudentID() { return this->studentID; }
string Student::getStudentNameFirst() { return this->studentNameFirst; }
string Student::getStudentNameLast() { return this->studentNameLast; }
string Student::getStudentEmail() { return this->studentEmail; }
int Student::getStudentAge() { return this->studentAge; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setStudentNameFirst(string studentNameFirst) { this->studentNameFirst = studentNameFirst; }
void Student::setStudentNameLast(string studentNameLast) { this->studentNameLast = studentNameLast; }
void Student::setStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDaysInCourse(int daysInCourse[]) { for (int i = 0; i < numDaysSize; ++i) this->daysInCourse[i] = daysInCourse[i]; }
void Student::setProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
	cout << this->getStudentID() << "\t";
	cout << "First Name: " << this->getStudentNameFirst() << "\t";
	cout << "Last Name: " << this->getStudentNameLast() << "\t";
	cout << "Age: " << this->getStudentAge() << "\t";
	cout << "daysInCourse: {" << this->getDaysInCourse()[0] << ", ";
	cout << this->getDaysInCourse()[1] << ", ";
	cout << this->getDaysInCourse()[2] << "}\t";
	cout << "Degree Program: " << degreeProgramName[this->getProgram()] << endl;
}