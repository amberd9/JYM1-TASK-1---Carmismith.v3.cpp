// JYM1 TASK 1 - Carmismith.v3.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
#include "vector"
#include <sstream>
using namespace std;

int main()
{
    cout << "Scripting and Programming - Applications – C867" << endl;
    cout << "C++" << endl;
    cout << "Student ID: #001405020" << endl;
    cout << "Amber Carmismith" << endl;

    roster classRoster;
    DegreeProgram degreeProgram;

    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Amber,Carmismith,acarmis@wgu.edu,31,52,56,56,SOFTWARE"
    };

    //Add each student to classRosterArray.
    //in roster.cpp not main?
    for (int i = 0; i < 5; i++){
        stringstream ss(studentData[i]);

        vector<string> resultVctr;

        while (ss.good()) {
            string subString;
            getline(ss, subString, ',');
            resultVctr.push_back(subString);
        }

        if (resultVctr[8] == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        if (resultVctr[8] == "NETWORK") {
            degreeProgram = DegreeProgram::NETWORK;
        }
        if (resultVctr[8] == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        }
        
        classRoster.add(resultVctr[0], resultVctr[1], resultVctr[2], resultVctr[3], stoi(resultVctr[4]), stoi(resultVctr[5]),
            stoi(resultVctr[6]), stoi(resultVctr[7]), degreeProgram);
    }


    cout << "Class Roster:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Invalid E-mails:" << endl;
    classRoster.printInvalidEmail();
    cout << endl;

    cout << "Average days to complete courses:" << endl;
    for (int i = 0; i < 5; i++) {
        //don't understand this!
        string tempString = "A" + to_string(i + 1);
        classRoster.printAvgDaysInCourse(tempString);
    }
    cout << endl;

    cout << "Students with a Software Degree:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Remove student A3" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Class Roster:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Remove student A3" << endl;
    classRoster.remove("A3");
    cout << "Student A3 not found" << endl;

    return 0;
}

roster::~roster() {}