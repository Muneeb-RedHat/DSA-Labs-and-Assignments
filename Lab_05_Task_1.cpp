// Queues
#include <iostream>
using namespace std;
int counter = 0;

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

        void enqueue(int val) {
            Node* newNode = new Node(val);
            if (front == nullptr) {
                front = newNode;
                rear = newNode;
                counter++;
            } else {
                rear->next = newNode;
                rear = newNode;
                counter++;
            }
        }

        int dequeue(){
            if (front == nullptr) {
                cout << "List is empty!" << endl;
                return-1;
            } else {
                Node* temp = front;
                int value = temp->data;
                front  = front->next;

                if (front == nullptr) {
                    rear = nullptr;
                }

                delete temp;
                temp = nullptr;
                counter--;
                return value;
            }
        }

        void reverse_at_k(int k){
            if(k < 0 || k > counter) {
                cout << "Add More or Less!" << endl;
                return;
            }
            int n = counter;
            int* temp = new int[n];
            // for elements till k (in reverse)
            for(int i = k - 1; i >= 0; i--) {
                temp[i] = dequeue();
            }
            
            // for rest of elements
            for(int i = k; i < n; i++) {
                temp[i] = dequeue();
            }

            for(int i = 0; i < n; i++) {
                enqueue(temp[i]);
            }

            delete[] temp;
            temp = nullptr;


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

int main () {

    Linked_list_queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);

    queue.display();

    queue.reverse_at_k(4000);
    queue.display();

    return 0;
}