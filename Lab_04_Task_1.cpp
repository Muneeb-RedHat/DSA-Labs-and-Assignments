#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

char stack[SIZE];
int top = -1;

bool isBalanced (string val) {
        for (int i = 0; i < val.length(); i++) {
            if (val[i] == '(' || val[i] == '{' || val[i] == '[') {
                top++;
                stack[top] = val[i];
            } else if (val[i] == ')' || val[i] == '}' || val[i] == ']') {
                if (top == -1) {
                    cout << "The stack is empty!" << endl;
                    return false;
                } else {
                    if (val[i] == ')' && stack[top] == '(') {
                        top--;
                    } else if (val[i] == '}' && stack[top] == '{') {
                        top--;
                    } else if (val[i] == ']' && stack[top] == '[') {
                        top--;
                    } else {
                        return false;
                    }
                }
            }
        }
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

int main () {

    string parenthesis;
    cout << "Enter paranthesis = ";
    cin >> parenthesis;

    if(isBalanced(parenthesis) == 1) {
        cout << "The setup is balanced." << endl;
    } else {
        cout << "The setup is not Balanced!" << endl;
    }

    return 0;
}