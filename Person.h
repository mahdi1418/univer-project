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
    Person(string fName ="", string lName="", int nID=0){
        firstName = fName;
        lastName = lName;
        nationalID = nID;
    }
    ~Person(){
        cout<<"Person class destroyed.\n";
    }

    void setFirstName(const string& fName) { firstName = fName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setNationalID(const long int& nID) { nationalID = nID; }

    string getFirstName(){ return firstName; }
    string getLastName(){ return lastName; }
    long int getNationalID(){ return nationalID; }

    void print(){
        cout << "Full name: " << firstName << " " << lastName << "\n ID: " << nationalID << endl;
    }
};


class Course {
private:
    int courseCode;
    string courseName;
    int vahed;
    string teacher;
    int capacity;
    int numberRegister;

public:
    void setCourseCode(int code) { courseCode = code; }
    void setCourseName(string name) { courseName = name; }
    void setVahed(int v) { vahed = v; }
    void setTeacherrName(string teach) { teacher = teach; }
    void setCapacity(int cap) { capacity = cap; }
    void setNumberRegister(int registCount) { numberRegister = registCount; }

    int getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }
    int getVahed() const { return vahed; }
    string getInstructorName() const { return teacher; }
    int getCapacity() const { return capacity; }
    int getEnrolledCount() const { return numberRegister; }

    bool isFull(){
        return numberRegister >= capacity;
    }

    void print(){
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Vahed : " << vahed << endl;
        cout << "teacher name: " << teacher << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number registered : " << numberRegister << endl;
        if (isFull()) {
            cout << "Status : Full" << endl;
        } else {
            cout << "Status : Available" << endl;
        }
}

    Course() {              //  سازنده پیش‌فرض
        courseCode = 0;
        courseName = "";
        vahed = 0;
        teacher = "";
        capacity = 0;
        numberRegister = 0;
    }

    Course(int code, string name, int v, string teach, int cap, int registCount) {           // 🔹 سازنده پارامتردار
        courseCode = code;
        courseName = name;
        vahed = v;
        teacher = teach;
        capacity = cap;
        numberRegister = registCount;
    }
    ~Course() {
        cout << "Course class destroyed: \n";
    }
};





class Student: public Person{
private:
    long int studentID;
    string field;  //رشته
    int term; //ترم
    Course lessons[13]; //هردرس 2واحد معدل الف 12 تا
    int numberLessons;
    float average;
public:
    void addCourse(){
        if (numberLessons >= 13) {
            cout << "Course limit reached!" << endl;
            return;
        }
        Course newCourse;
        string name, teacher;
        int code, vahed, cap;

        cout << "Enter course code: ";
        cin >> code;
        cin.ignore();
        cout << "Enter course name: ";
        getline(cin, name);
        cout << "Enter vahed: ";
        cin >> vahed;
        cin.ignore();
        cout << "Enter teacher name: ";
        getline(cin, teacher);
        cout << "Enter capacity: ";
        cin >> cap;

        newCourse.setCourseCode(code);
        newCourse.setCourseName(name);
        newCourse.setVahed(vahed);
        newCourse.setTeacherrName(teacher);
        newCourse.setCapacity(cap);
        newCourse.setNumberRegister(1);

        lessons[numberLessons] = newCourse;
        numberLessons++;
    }
    void removeCourse(){
        string lesson;
        cout<<"please enter lesson name :\n";
        cin>>lesson;
        for(int i=0;i<numberLessons;i++){
            if(lessons[i].getCourseName() ==lesson){
                for(int j=i;j<numberLessons;j++){
                    lessons[j]=lessons[j+1];
                }
                numberLessons--;
                break;
            }
        }
    }
    int calculateTotalUnits(){
        int totalVahed=0;
        for (int i = 0; i < numberLessons; i++) {
            totalVahed+=lessons[i].getVahed();
        }
        return totalVahed;
    }

    void print(){
        Person::print();
        cout << "studentID: " << studentID << endl;
        cout << "field of study: " << field << endl;
        cout << "current term: " << term << endl;
        cout << "number of selected lessons: " << numberLessons << endl;
        cout << "selected lessons: " << endl;
        for (int i = 0; i < numberLessons; i++) {
            cout << "- " << lessons[i].getCourseName() << endl;
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
        cout<<"student class destroyed.\n";
    }

};



#endif
