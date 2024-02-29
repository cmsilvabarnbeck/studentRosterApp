//
//  student.cpp
//  Performance Assessment
// This class represents a student that requires a studentID, first name, last name,
// email, age, an array with the days in their courses, and their degree program as
// parameters.
//
//  Created by Christopher Silva Barnbeck on 12/21/23.
//
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Constructor
Student::Student(string studentIDNumber, std::string firstNameData, std::string lastNameData, std::string emailData, int ageData, int daysInCourseData[3], DegreeProgram degreeProgramData){
    studentID = studentIDNumber;
    firstName = firstNameData;
    lastName = lastNameData;
    email = emailData;
    age = ageData;
    daysInCourse[0] = daysInCourseData[0];
    daysInCourse[1] = daysInCourseData[1];
    daysInCourse[2] = daysInCourseData[2];
    degreeProgram = degreeProgramData;
   
}

//Destructor
Student::~Student(){
    
}

//Getters and setters/Accessors and Mutators
void Student::setStudentID(string studentIDNumber) {
    this->studentID = studentIDNumber;
}

string Student::getStudentID(){
    return this->studentID;
}

void Student::setFirstName(string firstNameData){
    this->firstName = firstNameData;
}
string Student::getFirstName(){
    return this->firstName;
}
void Student::setLastName(string lastNameData){
    this->lastName = lastNameData;
}
string Student::getLastName(){
    return this->lastName;

}
void Student::setEmail(string emailData){
    this->email = emailData;
}
string Student::getEmail(){
    return this->email;

}
void Student::setAge(int ageData){
    this->age = ageData;
}
int Student::getAge(){
    return this->age;

}
void Student::setDaysInCourse(int daysInCourseData[3]){
    this->daysInCourse[0] = daysInCourseData[0];
    this->daysInCourse[1] = daysInCourseData[1];
    this->daysInCourse[2] = daysInCourseData[2];

}

const int* Student::getDaysInCourse(){
    return this->daysInCourse;

}
void Student::setDegreeProgram(DegreeProgram degreeProgramData){
    this->degreeProgram = degreeProgramData;
}
DegreeProgram Student::getDegreeProgram(){
    return this->degreeProgram;
}

//Prints all student details to console
void Student::print(){
    
    std::cout << this->studentID << "\t" << this->firstName << "\t" << this->lastName << "\t" << this->age << "\t" << "{" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}" << " " << degreeProgramStrings[(int) this->degreeProgram] << "\n";
}



