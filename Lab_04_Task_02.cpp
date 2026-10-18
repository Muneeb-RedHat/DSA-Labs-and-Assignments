#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

char stack[SIZE];
int top = -1;

bool isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(char value)
{
    if (top == SIZE - 1)
    {
        cout << "Stack is full!\n";
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

char pop()
{
    if (isempty())
    {
        cout << "Stack is empty!\n";
        return 0;
    }
    else
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

void reverse(string val) {
    for (char c: val) {
        push(c);
    }
    while (isempty() == false) {
        cout << pop();
    }
    cout << endl;
}

int main () {

    string reversal;

    cout << "Enter the required String = ";
    cin >> reversal;
    reverse(reversal);

    return 0;
}