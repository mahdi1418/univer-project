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
    int nationalID;

public:
    Person(string fName ="", string lName="", int nID=0){
        firstName = fName;
        lastName = lName;
        nationalID = nID;
    }
//    ~Person(){
//        cout<<"Person class destroyed.\n";
//    }

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
    string getTeacherName() const { return teacher; }
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
//    ~Course() {
//        cout << "Course class destroyed: \n";
//    }
};





class Student: public Person{
private:
    int studentID;
    string field;  //رشته
    int term; //ترم
    Course lessons[13]; //هردرس 2واحد معدل الف 12 تا
    int numberLessons;
    float average;
public:
//    void addCourse(){
//        if (numberLessons >= 13) {
//            cout << "Course limit reached!" << endl;
//            return;
//        }
//
//        string name, teacher;
//        int code, vahed;
//
//        cout << "Enter course code: ";
//        cin >> code;
//        cout << "Enter course name: ";
//        cin>>name;
//        cout << "Enter vahed: ";
//        cin >> vahed;
//        cout << "Enter teacher name: ";
//        cin >>teacher;
//
//        for(int i=0;i<courseCount && status=0;i++){
//            if(course[i].getCourseName() ==name && course[i].getCourseCode() ==code && course[i].getTeacherName() ==teacher && course[i].getVahed() ==vahed){
//                for(int j=i;j<courseCount;j++){
//                    course[j]=course[j+1];
//                }
//                numberLessons++;
//                status=1;
//                break;
//            }
//        }
//
//    }

//    void removeCourse(){
//        string lesson;
//        cout<<"please enter lesson name :\n";
//        cin>>lesson;
//        for(int i=0;i<numberLessons;i++){
//            if(lessons[i].getCourseName() ==lesson){
//                for(int j=i;j<numberLessons;j++){
//                    lessons[j]=lessons[j+1];
//                }
//                numberLessons--;
//                break;
//            }
//        }
//    }

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
        cout << "total vahed : " << calculateTotalUnits() << endl;
    }
    Student() : Person(){           //پیشفرض
        studentID = 0;
        field = "";
        term = 0;
        numberLessons = 0;
        average = 0.0;
    }
    Student(string fName, string lName, int nID, //پارامتر
            int sID, string f, int t,int nl, float a)
        : Person(fName, lName, nID){
        studentID = sID;
        field = f;
        term = t;
        numberLessons =nl;
        average = a;
    }
//    ~Student(){
//        cout<<"student class destroyed.\n";
//    }

};

class Admin: public Person{
private:



};

class UniversitySystem{
private:
    Student student[1000];
    int studentCount=0;
    Course course[100];
    int courseCount=0;
public:
    void addStudent(){
        string name,lname;
        int id;
        cout<<"enter name :";
        cin>>name;
        student[studentCount].setFirstName(name);
        cout<<"enter lastname :";
        cin>>lname;
        student[studentCount].setLastName(lname);
        cout<<"enter national id :";
        cin>>id;
        student[studentCount].setNationalID(id);
        studentCount++;

    }
    void removeStudent(){
        string name,lname;
        int id;
        cout<<"enter student name :";
        cin>>name;
        cout<<"enter lastname :";
        cin>>lname;
        cout<<"enter national id :";
        cin>>id;

        for(int i=0;i<studentCount;i++){
            if(student[i].getFirstName() ==name && student[i].getLastName() ==lname && student[i].getNationalID() ==id){
                for(int j=i;j<studentCount;j++){
                    student[j]=student[j+1];
                }
                studentCount--;
                break;
            }
        }
    }
    void addCourse(){
        string name, teach;
        int code, v,cap;
        cout<<"enter course name :";
        cin>>name;
        course[courseCount].setCourseName(name);
        cout<<"enter course code :";
        cin>>code;
        course[courseCount].setCourseCode(code);
        cout<<"enter vahed :";
        cin>>v;
        course[courseCount].setVahed(v);
        cout<<"enter capacity :";
        cin>>cap;
        course[courseCount].setCapacity(cap);
        cout<<"enter teacher name :";
        cin>>teach;
        course[courseCount].setTeacherrName(teach);

        courseCount++;
    }
    void removeCourse(){
        string name, teach;
        int code;
        cout<<"enter course name :";
        cin>>name;
        cout<<"enter course code :";
        cin>>code;
        cout<<"enter teacher name :";
        cin>>teach;
            for(int i=0;i<courseCount;i++){
            if(course[i].getCourseName() ==name && course[i].getCourseCode() ==code && course[i].getTeacherName() ==teach){
                for(int j=i;j<studentCount;j++){
                    course[j]=course[j+1];
                }
                courseCount--;
                break;
            }
        }
    }
    void studentLogin(){

    }
    void adminLogin(){

    }
    void displayAllCourses(){
        for(int i=0;i<courseCount;i++){
            cout<<" course name : "<<course[i].getCourseName();
            cout<<" course code : "<<course[i].getCourseCode();
            cout<<" course vahed : "<<course[i].getVahed();
            cout<<" teacher name : "<<course[i].getTeacherName();
            cout<<" capacity : "<<course[i].getCapacity();
            cout<<" number of Register : "<<course[i].getEnrolledCount();
        }
    }

    void displayStudentInfo(){
        int id;
        cout<<"enter national id : ";
        cin>>id;
        for(int i=0;i<studentCount;i++){
            if(student[i].getNationalID()==id){
                student[i].print();
                exit;
            }
        }
    }
    void saveToFile(){

    }
    void loadFromFile(){

    }
    ~UniversitySystem(){
        cout<<"University System class destroyed.\n";
    }

//    void save() {
//        ofstream outFile("shop-list.txt");
//        if (!outFile){
//            cout<<"file not founded!!";
//            return;
//        }
//        outFile <<count<<endl ;
//        for (int i = 0; i < count; i++) {
//            outFile << student[i].name << " " << student[i].amount << " " << student[i].price << endl;
//        }
//        outFile.close();
//    }

//    void load() {
//        ifstream inFile("shop-list.txt");
//        if (!inFile){
//            cout<<"file not founded!!";
//            return;
//        }
//        inFile >> count;
//        for (int i = 0; i < count; i++) {
//            inFile >> products[i].name >> products[i].amount >> products[i].price;
//        }
//        inFile.close();
//    }

};


#endif
