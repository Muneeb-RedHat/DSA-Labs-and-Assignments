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

class Linked_list {
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        void push_back(int val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front(){
            if (head == nullptr) {
                cout << "List is empty!" << endl;
            } else {
                Node* temp = head;
                head  = head->next;

                if (head == nullptr) {
                    tail = nullptr;
                }

                delete temp;
                temp = nullptr;
            }
        }

        void search(int val) {
            Node* temp = head;
            while(temp != nullptr) {
                if (temp->data == val) {
                    cout<< "Required Id is found!" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Required Id not found!" << endl;

        }

        void display(){
            Node* temp = head;
            while(temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "Null" << endl;
        }
};

int main () {

    Linked_list Student_ids;

    Student_ids.push_back(101);
    Student_ids.push_back(102);
    Student_ids.push_back(103);
    Student_ids.push_back(104);

    Student_ids.display();

    Student_ids.search(103);
    Student_ids.search(999);


    return 0;
}