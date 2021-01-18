#pragma once
#include "student.h"
#include <array>
using namespace std;

class roster{

public:
    roster(); 

	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int course1, int course2, int course3, DegreeProgram degreeProgram);
	void remove(string studentId);
    void printAll();
    void printAvgDaysInCourse(string studentId);
    void printInvalidEmail();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    int iterator = 0;

    ~roster();

private:
    student* classRosterArray[5];

};

