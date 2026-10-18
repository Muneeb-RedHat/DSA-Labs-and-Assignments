#include <iostream>
using namespace std;

// struct Student{

//     string name;
//     int age;
//     string section;
// };

// // void display(Student s) {
// //     cout << "Name: " << s.name << endl;
// //     cout << "Age: " << s.age << endl;
// //     cout << "Section: " << s.section << endl;
// // }

// int main () {
//     Student s = {"Muneeb Sajid", 20, "B"};
//     Student *sp = &s;
//     cout << "Name: " << sp->name << endl;
//     cout << "Age: " << sp->age << endl;
//     cout << "Section: " << s.section << endl;
//     //display(s);
//     return 0;
// }
int main() {

    // int x = 10;
    // int *p = &x;
    // *p = 1000;

    // cout << "Value: " << x << endl;
    // cout << "Address: " << &x << endl;
    // cout << "Pointer: " << p << endl;
    // cout << "Value using pointer: " << *p << endl;

    // int x = 30;
    // int *ptr1 = &x;
    // cout << ptr1 << endl;
    // int **ptr2 = &ptr1;
    // cout << *ptr2 << endl;

    // int n = 5;
    // int *arr = new int[n];

    // for (int i = 0; i < n; i++) {
    //     arr[i] = (i + 1)* 10;
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;
    // delete[] arr;
    // arr = nullptr;

    int rows = 6, cols = 4;
    int *a = new int[rows * cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i*cols +j] = i + j;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i*cols + j] << " ";
        }
        cout << endl;
    }
    delete[] a;
    a = nullptr;

    return 0;
}