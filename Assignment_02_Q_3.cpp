#include <iostream>
using namespace std;
const int SIZE = 100;

class Stack {
    private:
        int arr[SIZE];
        int top;
    public:
        Stack() { 
            top = -1; 
        }

        bool isEmpty() { 
            return top == -1; 
        }

        void push(int x) { 
            arr[++top] = x; 
        }

        int pop() { 
            return arr[top--]; 
        }
};

class Queue {
    private:
        Stack s1, s2;
    public:
        void enqueue(int x) {
            s1.push(x);               // 1st in stack 
    }
        int dequeue() {
            if (s2.isEmpty()) {       // only when empty
                while (!s1.isEmpty())
                    s2.push(s1.pop());
            }
            if (s2.isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
        return s2.pop();
    }
};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeue: " << q.dequeue() << endl;

    q.enqueue(40);
    
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    return 0;
}