#pragma once
#include <string>
#include "degree.h"
using namespace std;

class student{

public:

	//Create accessors, part D.2
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	//Create mutators, part D.2
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(int day0, int day1, int day2);
	//void SetDaysInCourse(int daysInCourse[3]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//create constructors in student.h or student.cpp
	
	//constructor
	student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
	
	//destructor
	~student();
	
	//needed?
	virtual void print();
	virtual DegreeProgram GetDegreeProgram() = 0;

private:

	//define variables, part D1
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

};


