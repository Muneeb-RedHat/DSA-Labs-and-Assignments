// Queues
#include <iostream>
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

class Linked_list_queue {
    public:
        Node* front = nullptr;
        Node* rear = nullptr;

        void push_back(int val) {
            Node* newNode = new Node(val);
            if (front == nullptr) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void pop_front(){
            if (front == nullptr) {
                cout << "List is empty!" << endl;
            } else {
                Node* temp = front;
                front  = front->next;

                if (front == nullptr) {
                    rear = nullptr;
                }

                delete temp;
                temp = nullptr;
            }
        }

        void display(){
            Node* temp = front;
            while(temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {

    Linked_list_queue queue;
    queue.push_back(10);
    queue.push_back(20);
    queue.push_back(30);

    queue.display();

    queue.pop_front();

    queue.display();

    queue.pop_front();
    queue.pop_front();

    queue.display();

    return 0;
}