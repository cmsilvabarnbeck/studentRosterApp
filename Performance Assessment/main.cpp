//
//  main.cpp
//  Performance Assessment
//  This program will parse and display student information.
//
//  Created by Christopher Silva Barnbeck on 12/21/23.
//
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Required heading
    std::cout << "C867 - Scripting & Programming: Applications\nLanguage: C++\nStudent ID: 009923619\nName: Christopher Silva Barnbeck\n\n";
    //Creating classRoster object and array of studentData
    Roster classRoster;
    const string studentData [] =
    {"A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
        "A3, Jack, Napoli, The_lawyer99yahoo.com, 19,20, 40, 33, SOFTWARE" ,
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
        "A5, Christopher, Silva Barnbeck, csil135@wgu.edu, 34, 53, 30, 55, SOFTWARE"};
    //Loop through size of array to parse each row
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++){
        classRoster.parse(studentData[i]);
    };
    std::cout << "Displaying all students:\n";
    classRoster.printAll();
    std::cout << "Displaying invalid emails:\n\n";
    classRoster.printInvalidEmails();
    //Loop through all students and print average days in course
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++){
        string student = (string)classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(student);
    }
    std::cout << "\n";
    std::cout << "Showing students in degree program: SOFTWARE\n\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "Removing A3: \n";
    classRoster.remove("A3");
    classRoster.printAll();
    std::cout << "Removing A3 again: \n\n";
    classRoster.remove("A3");
    std::cout << "DONE\n";
};
