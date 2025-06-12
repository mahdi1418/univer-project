#include <iostream>
#include <string>
#include "person.h"

using namespace std;

int main()
{
    Person p1("mahdi","cript",403441180);
    Person p2("ali");
    p1.print();
    p2.print();
    return 0;
}
