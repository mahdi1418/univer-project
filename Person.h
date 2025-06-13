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

    void setFirstName(const string& fName) { firstName = fName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setNationalID(const int& nID) { nationalID = nID; }

    string getFirstName(){ return firstName; }
    string getLastName(){ return lastName; }
    int getNationalID(){ return nationalID; }

    void print(){
        cout << "Full name: " << firstName << " " << lastName << "\n ID: " << nationalID << endl;
    }
};

class Student: public Person{
private:
    long int studentID;
    string field;  //رشته
    int term; //ترم
    string lessons[13]; //هردرس 2واحد معدل الف 12 تا
    int numberLessons;
    float average;
    int vahed[13];
public:
    void addCourse(){
        string lesson;
        int v;
        cout<<"please enter lesson name and vahed :\n";
        cin>>lesson;
        cin>>v;
        lessons[numberLessons]=lesson;
        vahed[numberLessons]=v;
        numberLessons++;
    }
    void removeCourse(){
        string lesson;
        cout<<"please enter lesson name :\n";
        cin>>lesson;
        for(int i=0;i<numberLessons;i++){
            if(lessons[i]==lesson){
                for(int j=i;j<numberLessons;j++){
                    lessons[j]=lessons[j+1];
                    vahed[j]=vahed[j+1];
                }
                numberLessons--;
                break;
            }
        }
    }
    int calculateTotalUnits(){      //واحدها
        int totalVahed=0;
        for (int i = 0; i < numberLessons; i++) {
            totalVahed+=vahed[i];
        }
        return totalVahed;
    }
    void print(){
        Person::print();  // نمایش اطلاعات از کلاس پایه
        cout << "studentID: " << studentID << endl;
        cout << "field of study: " << field << endl;
        cout << "current term: " << term << endl;
        cout << "number of selected lessons: " << numberLessons << endl;
        cout << "selected lessons: " << endl;
        for (int i = 0; i < numberLessons; i++) {
            cout << "- " << lessons[i] << endl;
        }
        cout << "average: " << average << endl;
    }
    Student() : Person(){           //پیشفرض
        studentID = 0;
        field = "";
        term = 0;
        numberLessons = 0;
        average = 0.0;
    }
    Student(string fName, string lName, int nID, //پارامتر
            long int sID, string f, int t,int nl, float a)
        : Person(fName, lName, nID){
        studentID = sID;
        field = f;
        term = t;
        numberLessons =nl;
        average = a;
    }
    ~Student(){
        cout<<"student class destroyed.";
    }








};
#endif
