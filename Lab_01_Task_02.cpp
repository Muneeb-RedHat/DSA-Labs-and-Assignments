#include <iostream>
using namespace std;

struct Student{

    string name;
    int roll_no;
    int age;
    string address;
};

int main () {

    int n;
    cout << "Enter thge no. of students (More than 10): ";
    cin >> n;
    Student *arr = new Student[n];

    for (int i = 0; i < n; i++) {
        cout<<"Enter Student info " << i + 1 << endl;
        cin>> arr[i].name;
        cin>> arr[i].roll_no;
        cin>> arr[i].age;
        cin>> arr[i].address;
    }


    for (int i = 0; i < n; i++) {
        cout<< "Print Info of Student" << i + 1 << endl;
        cout<< arr[i].name << endl;
        cout<< arr[i].roll_no << endl;
        cout<<arr[i].age << endl;
        cout<< arr[i].address << endl;
    }

    return 0;
}