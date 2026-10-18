#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;

class Stack {
    private:
        char arr[SIZE];
        int top;
    public:
        Stack() { 
            top = -1; 
        }

        void push(char c) { 
            arr[++top] = c; 
        }

        char pop() { 
            return arr[top--]; 
        }
};

class Queue {
    private:
        char arr[SIZE];
        int front, rear;
    public:
        Queue() { 
            front = 0; rear = -1; 
        }

        void enqueue(char c) { 
            arr[++rear] = c; 
        }

        char dequeue() { 
            return arr[front++]; 
        }
};

int main() {

    string word;
    cout << "Enter a word: ";
    cin >> word;

    Stack s;
    Queue q;
    
    for (int i = 0; i < word.length(); i++) {
        s.push(word[i]);
        q.enqueue(word[i]);
    }

    bool palindrome = true;
    for (int i = 0; i < word.length(); i++) {
        if (s.pop() != q.dequeue()) {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << word << " is a palindrome" << endl;
    else
        cout << word << " is not a palindrome" << endl;

    return 0;
}