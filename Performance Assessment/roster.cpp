//
//  roster.cpp
//  Performance Assessment
//  This class represents a roster object that can add, remove, and print the details of
//  student objects
//
//  Created by Christopher Silva Barnbeck on 12/21/23.
//
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//To keep track of our students
int counter = 0;

//Sets default degree program to software if there is no match, otherwise it matches to parallel string
DegreeProgram stringToEnum(string studentDegree){
    if (studentDegree == " " + degreeProgramStrings[0]){
        return SECURITY;
    } else if (studentDegree == " " + degreeProgramStrings[1]){
        return NETWORK;
    } else if (studentDegree == " " + degreeProgramStrings[2]){
        return SOFTWARE;
    } else {
        return SOFTWARE;
    }
}

//Constructor
Roster::Roster(){
    
}

//Destructor
Roster::~Roster(){
    for (int i=0; i < counter; i++)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
  
}

//Parses a string and adds to roster
void Roster::parse(string row){
    char row2[row.size()+1]; // +1 added for the null pointer
    strcpy(row2, row.c_str());
    //strtok to parse by comma as delimeter
    strtok(row2, ",");
    string ID = string(row2);
    string fName = strtok(NULL, ",");
    string lName = strtok(NULL, ",");
    string email = strtok(NULL, ",");
    string studentAge = strtok(NULL, ",");
    string daysInCourse1a = strtok(NULL, ",");
    string daysInCourse2a = strtok(NULL,",");
    string daysInCourse3a = strtok(NULL, ",");
    string studentDegree = strtok(NULL, ",");
    
    //Calls the add function while converting strings to ints and studentDegree string to its Enum
    add(ID, fName, lName, email, stoi(studentAge), stoi(daysInCourse1a), stoi(daysInCourse2a),stoi(daysInCourse3a),stringToEnum(studentDegree));



    
}


//Adds a student to the Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    int allDaysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //If this is the first object going into the classRosterArray we first have to create the classRosterArray as an array of new student pointers
    if (classRosterArray == NULL){
        classRosterArray = new Student*;
        classRosterArray[counter] = new Student(studentID, firstName, lastName, emailAddress, age, allDaysInCourse, degreeprogram);

    } else {
        classRosterArray[counter] = new Student(studentID, firstName, lastName, emailAddress, age, allDaysInCourse, degreeprogram);
    }
    //Counter incremented each time new student is added
    counter++;
    }


// Removes a student based on their provided student ID
void Roster::remove(string studentID){
    // Track if student ID was even found in data set
    int studentIDFound = 0;
    for (int i = 0; i < counter; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            studentIDFound = 1;
        }
    }
        if (studentIDFound == 1){
            //Default value for index we want deleted is set to 0, but won't run unless studentID is found and matches
            int indexWeWantDeleted = 0;
            for (int i = 0; i < counter; i++){
                if (classRosterArray[i]->getStudentID() == studentID){
                    //Important: i+1 for the null pointer
                    indexWeWantDeleted = i+1;
                }
            }
            for (; indexWeWantDeleted < counter; indexWeWantDeleted++){
                classRosterArray[indexWeWantDeleted-1] = classRosterArray[indexWeWantDeleted];
            }
            //Decrement counter
            counter--;
        } else {
            std::cout << "The student with the ID: " << studentID << " was not found.\n";
            
        }
        std::cout << "\n";
        
    }

//Loops through each student in roster and prints
void Roster::printAll(){
    for (int i = 0; i < counter; i++){
        classRosterArray[i]->print();
    }
    std::cout << "\n";
    
}

// Prints average days in student courses accepting string student ID as a parameter
void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i < counter; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            std::cout << "Student ID: " << studentID << ", average days in course is: " << ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2])/3);
            
        }
        
    }

    std::cout << "\n";

}

//Prints invalid emails by looking for spaces, at least 1 dot, and at least 1 @ symbol
void Roster::printInvalidEmails(){
    for (int i = 0; i < counter; i++){
        for(int j = 1; j < classRosterArray[i]->getEmail().size()-1; j++){
            if((isspace(classRosterArray[i]->getEmail()[j]))){
                std::cout << classRosterArray[i]->getEmail() << " - is invalid.\n";
                break;
            }
            string invalidEmail = classRosterArray[i]->getEmail();
            if(!(invalidEmail.find("@") < invalidEmail.length()) || !(invalidEmail.find(".") < invalidEmail.length())){
                std::cout << classRosterArray[i]->getEmail() << " - is invalid.\n";
                break;
            }
        }

    }
    std::cout << "\n";

}

// Prints students by their degree program which is passed in as type enum
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){

    for (int i = 0; i < counter; i++){
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    
    }
    std::cout << "\n";
}
