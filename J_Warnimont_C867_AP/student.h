#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip> 
using namespace std;

#include "degree.h"

class Student
{
public:
	const static int numDaysSize = 3;

private:
	string studentID;
	string studentNameFirst;
	string studentNameLast;
	string studentEmail;
	int studentAge;
	int daysInCourse[numDaysSize];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentID, string studentNameFirst, string studentNameLast, string studentEmail, int studentAge, int days[], DegreeProgram degreeProgram);
	~Student();

	string getStudentID();
	string getStudentNameFirst();
	string getStudentNameLast();
	string getStudentEmail();
	int getStudentAge();
	int* getDaysInCourse();
	DegreeProgram getProgram();

	void setStudentID(string studentID);
	void setStudentNameFirst(string studentNameFirst);
	void setStudentNameLast(string studentNameLast);
	void setStudentEmail(string studentEmail);
	void setStudentAge(int studentAge);
	void setDaysInCourse(int daysInCourse[]);
	void setProgram(DegreeProgram degreeProgram);

	void print();
};

#endif