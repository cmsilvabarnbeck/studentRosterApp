//
//  roster.h
//  Performance Assessment
//
//  Created by Christopher Silva Barnbeck on 12/21/23.
//


#pragma once
#include <stdio.h>
#include "student.h"

class Roster
{
public:
    Student **classRosterArray;
    Roster();
    ~Roster();
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
};
