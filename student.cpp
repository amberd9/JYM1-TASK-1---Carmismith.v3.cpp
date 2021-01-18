#include "student.h"
#include <iostream>
#include "degree.h"
//#include <array>
//#include <string>
using std::string;
using std::cout;
using std::endl;
using namespace std;

//define function, accessors part D2

string student::GetStudentId() {
	return studentId;
}

string student::GetFirstName() {
	return firstName;
}

string student::GetLastName() {
	return lastName;
}

string student::GetEmailAddress() {
	return emailAddress;
}

int student::GetAge() {
	return age;
} 

int* student::GetDaysInCourse() {
	return daysInCourse;
	//was int*
}

DegreeProgram student::GetDegreeProgram() {
	return degreeProgram;
}

//define function, mutators part D2

void student::SetStudentId(string studentId) {
	this->studentId = studentId;
	//fix me?
}

void student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void student::SetAge(int age) {
	this->age = age;
}

void student::SetDaysInCourse(int daysInCourse0, int daysInCourse1, int daysInCourse2) {
	student::daysInCourse[0] = daysInCourse0;
	student::daysInCourse[1] = daysInCourse1;
	student::daysInCourse[2] = daysInCourse2;
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
		//needed for statement?
	}
}
void student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	}//use enumerated data or "string"? was "string" before, trying enumerated data

//define constructor, part d2.d
//do i need an empty constructor too?

student::student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram) {

	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this-> emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
		//proper array formatting??
	this->degreeProgram = degreeProgram;
}

//printing function

void student::print() {

	cout << GetStudentId();
	cout << "\tFirst Name: " << GetFirstName();
	cout << "\tLast Name: " << GetLastName();
	cout << "\tE-mail: " << GetEmailAddress();
		//needed in addition to email check?
	cout << "\tAge: " << GetAge();
	//int* student::*GetDaysInCourse();
	//int* daysInCourse = GetDaysInCourse();
	//do i need to call this ^^
	cout << "\tDays to Complete 3 Courses: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2];
	//incorrect use of &? do i need &? &daysInCourse[0] 
	//daysInCourse[0] or day[0]
	cout << "\tDegree Program: " << GetDegreeProgram << endl;
	////incorrect use of &? do i need &?
}

//define destructor, part d2.d

student::~student() {
}



