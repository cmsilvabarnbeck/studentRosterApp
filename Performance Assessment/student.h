//
//  student.hpp
//  Performance Assessment
//
//  Created by Christopher Silva Barnbeck on 12/21/23.
//

#pragma once
#include <stdio.h>
#include <string>
#include "degree.h"

using namespace std;

class Student
{
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
public:
    //Constructor
    Student(string studentIDNumber, string firstNameData, string lastNameData, string emailData, int ageData,int daysInCourseData[3], DegreeProgram degreeProgramData);
    //Destructor
    ~Student();
    //Getters and Setters/Accessors and Mutators
    void setStudentID(string studentIDNumber);
    string  getStudentID();
    void setFirstName(string firstNameData);
    string getFirstName();
    void setLastName(string lastNameData);
    string getLastName();
    void setEmail(string emailData);
    string getEmail();
    void setAge(int ageData);
    int getAge();
    void setDaysInCourse(int daysInCourseData[3]);
    const int* getDaysInCourse();
    void setDegreeProgram(DegreeProgram degreeProgramData);
    DegreeProgram getDegreeProgram();
    void print();
};



