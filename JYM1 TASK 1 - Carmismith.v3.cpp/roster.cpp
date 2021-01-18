#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <array>
#include <vector>

//constructor
roster::roster(){};

// Adding student to roster object, part E.3.a
//public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
//int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1
//and updates the roster.
//compared to Create a student object for each student in the data table and populate classRosterArray
void roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int courses[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    // need pointers?

    switch (degreeProgram) {
    case 0:
        classRosterArray[iterator++] = new student(studentId, firstName, lastName, emailAddress, age, courses, degreeProgram);
        break;
    case 1:
        classRosterArray[iterator++] = new student(studentId, firstName, lastName, emailAddress, age, courses, degreeProgram);
        break;
    case 2:
        classRosterArray[iterator++] = new student(studentId, firstName, lastName, emailAddress, age, courses, degreeProgram);
        break;
    default:
        cout << "error" << endl;
    }
}

// Printing by Degree for students, part E.3.f
// public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information 
//for a degree program specified by an enumerated type.
    void roster::printByDegreeProgram(DegreeProgram degreeProgram){
       for (int i = 0; i < 5; i++) {
         if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == SOFTWARE) {
        //SOFTWARE?
        classRosterArray[i]->print();
    }
}
    }

// Removing student to roster object, part E.3.b
//  public void remove(string studentID)  that removes students from the roster by student ID. 
//If the student ID does not exist, the function prints an error message indicating that the student was not found.
    void roster::remove(string studentId) {
        for (int i = 0; i < 5; i++) {
            //5 or 9
            if (classRosterArray[i] != nullptr && studentId == classRosterArray[i]->GetStudentId()) {
                classRosterArray[i] = nullptr;
                cout << "Student Id " << studentId << " was removed." << endl;
            }
            else if (classRosterArray[i] == nullptr) {
                cout << "Student Id " << studentId << " was not found." << endl;
            }
        }
    }

// Printing all studentData, part E.3.c 
//public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: 
//John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function 
//should loop through all the students in classRosterArray and call the print() function for each student.
    void roster::printAll() {
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] != nullptr) {
                classRosterArray[i]->print();
            }
        }
    }

// Printing average days to complete courses, part E.3.d
//  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
        void roster::printAvgDaysInCourse(string studentId) {
            for (int i = 0; i < 5; i++) {
                if (studentId == classRosterArray[i]->GetStudentId()) {
                    int* courses = classRosterArray[i]->GetDaysInCourse();
                    //GetCourses or daysInCourses?
                    double avg = ((double)courses[0] + (double)courses[1] + (double)courses[2]) / 3.0;

                    cout << fixed << setprecision(1);
                    cout << studentId << ": " << avg << " average days spent in course." << endl;
                }
            }
        }

// Invalid email addresses, part E.3.e
//public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the use
void roster::printInvalidEmail() {
    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i]->GetEmailAddress();

        size_t findAtSymbol = email.find("@");
        if (findAtSymbol == string::npos) {
            cout << email << "Error: E-mail missing '@'." << endl;
        }

        size_t findPeriod = email.find(".");
        if (findPeriod == string::npos) {
            cout << email << "Error: E-mail has no '.'." << endl;
        }

        size_t findWhiteSpace = email.find(" ");
        if (findWhiteSpace != string::npos) {
            cout << email << "Error: E-mail cannot have any spaces." << endl;
        }
    }
    //deconstructor
    roster::~roster();
    }



