#include <iostream>
#include <string>
#include "person.h"

using namespace std;

int main()
{
//    Person p1("mahdi","cript",403441180);
//    Person p2("ali");
//    p1.print();
//    p2.print();


//    Student s1;
//    s1.addCourse();
//    s1.addCourse();
//    s1.print();
//


//    Course c1(101, "math", 3, "Dr. Ahmadi", 30, 25);
//    c1.print();
//
//    if (c1.isFull())
//        cout << "This course is full." << endl;
//    else
//        cout << "You can register for this course." << endl;



    Student s;
    s.addCourse();
    s.addCourse();
    s.print();

    cout << "Total Units: " << s.calculateTotalUnits() << endl;













    return 0;
}
