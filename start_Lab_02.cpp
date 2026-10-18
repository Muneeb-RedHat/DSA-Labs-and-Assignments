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

        void push_front(int val){
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

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

        void pop_back() {
            if (head == nullptr) {
                cout << "List is empty!" << endl;
            } else if (head == tail){
                    delete head;
                    head = nullptr;
                    tail = nullptr;
            } else {
                Node* temp = head;
                while((temp->next)->next != nullptr) {
                    temp = temp->next;
                }
                tail = temp;
                temp = temp->next;
                tail->next = nullptr;
                delete temp;
            }
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

    Linked_list list;
    list.push_front(7);
    list.push_front(9);
    list.push_back(10);
    list.pop_back();
    list.display();


    return 0;
}