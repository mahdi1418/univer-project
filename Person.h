#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    long int nationalID;

public:
    Person(string fName ="", string lName="", int nID=00000000){
        firstName = fName;
        lastName = lName;
        nationalID = nID;
    }
    ~Person(){
        cout<<"Person class destroyed.";
    }

    void setFirstName(string& fName) { firstName = fName; }
    void setLastName(string& lName) { lastName = lName; }
    void setNationalID(int& nID) { nationalID = nID; }

    string getFirstName(){ return firstName; }
    string getLastName(){ return lastName; }
    int getNationalID(){ return nationalID; }

    void print(){
        cout << "Full name: " << firstName << " " << lastName << ", ID: " << nationalID << endl;
    }
};
class Student: public Person{
public:
    long int StudentID;
    string field;  //رشته
    int semester; //ترم
    string lessons[13]; //هردرس 2واحد معدل الف 12 تا
    int numberLessons;
    float average;

    void addCourse(){

    }
    void removeCourse(){

    }
    void calculateTotalUnits{        //واحدها

    }
    void print(){

    }
    Student(){  //پیش فرض
        firstName = fName;
        lastName = lName;
        nationalID = nID;
    }
    Student(string fName ="", string lName="", int nID=00000000){ //پارامتر
        firstName = fName;
        lastName = lName;
        nationalID = nID;
    }
    ~Student(){
        cout<<"student class destroyed.";
    }

































};
#endif
