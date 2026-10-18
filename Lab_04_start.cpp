// #include <iostream>
// using namespace std;

// #define SIZE 7

// int A[SIZE];
// int top = -1;

// bool isempty()
// {
//     if (top == -1)
//         return true;
//     else
//         return false;
// }

// void push(int value)
// {
//     if (top == SIZE - 1)
//     {
//         cout << "Stack is full!\n";
//     }
//     else
//     {
//         top++;
//         A[top] = value;
//     }
// }

// void pop()
// {
//     if (isempty())
//     {
//         cout << "Stack is empty!\n";
//     }
//     else
//     {
//         top--;
//     }
// }

// void show_top()
// {
//     if (isempty())
//     {
//         cout << "Stack is empty!\n";
//     }
//     else
//     {
//         cout << "Element at top is: " << A[top] << "\n";
//     }
// }

// void displayStack()
// {
//     if (isempty())
//     {
//         cout << "Stack is empty!\n";
//     }
//     else
//     {
//         for (int i = 0; i <= top; i++)
//             cout << A[i] << " ";

//         cout << "\n";
//     }
// }

// int main()
// {
//     int choice, flag = 1, value;

//     while (flag == 1)
//     {
//         cout << "\n1. PUSH  2. POP  3. SHOW_TOP  4. DISPLAY_STACK  5. EXIT\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//             if (choice == 1) {
//                 cout << "Enter Value: ";
//                 cin >> value;
//                 push(value);
//             } else if (choice == 2) {
//                 pop();
//             } else if (choice == 3) {
//                 show_top();
//             } else if (choice == 4) {
//                 displayStack();
//             } else if (choice == 5) {
//                 flag = 0;
//                 cout << "Exiting program...\n";
//             } else {
//                 cout << "Invalid choice!" << endl;
//             }

//         // switch (choice)
//         // {
//         //     case 1:
//         //         cout << "Enter Value: ";
//         //         cin >> value;
//         //         push(value);
//         //         break;

//         //     case 2:
//         //         pop();
//         //         break;

//         //     case 3:
//         //         show_top();
//         //         break;

//         //     case 4:
//         //         displayStack();
//         //         break;

//         //     case 5:
//         //         flag = 0;
//         //         cout << "Exiting program...\n";
//         //         break;

//         //     default:
//         //         cout << "Invalid choice!\n";
//         // }
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
};

class Stack {
    public:
        Node* top = NULL;

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top == nullptr) {
                cout << "Stack is empty!\n";
                return;
            }

            Node* temp = top;
            top = top->next;
            delete temp;
        }

};

int main () {
    return 0;
}