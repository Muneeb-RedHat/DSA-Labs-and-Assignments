#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    double salary;
};

void display(Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "Salary: " << p.salary << endl;
}
int main () {

    Person p = {"Muneeb Sajid", 21, 10973398038.980};

    display(p);

    return 0;
}