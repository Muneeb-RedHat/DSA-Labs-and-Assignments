#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) { 
        data = d; next = NULL; 
    }
};

class LinkedStack {
    private:
        Node* top;
    public:
        LinkedStack() { 
            top = NULL; 
        }

        bool isEmpty() { 
            return top == NULL; 
        }

        void push(int x) {
            Node* n = new Node(x);
            n->next = top;
            top = n;
        }

        int pop() {
            Node* temp = top;
            int x = temp->data;
            top = top->next;
            delete temp;
            return x;
        }
};

int main() {

    int num;
    cout << "Enter a positive decimal number: ";
    cin >> num;

    if (num <= 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    LinkedStack st;

    while (num > 0) {
        st.push(num % 2);   // pushing the  remainder
        num = num / 2;
    }

    cout << "Binary: ";

    while (!st.isEmpty()) {
        cout << st.pop();   // poping gives us the correct order
    }
    cout << endl;

    return 0;
}