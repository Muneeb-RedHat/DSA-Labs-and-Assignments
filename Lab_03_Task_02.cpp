#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class doublyLinked_list {
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
                head->prev = newNode;
                head = newNode;
            }
        }

        void push_back(int val) {
            Node* newNode = new Node(val);
            if(head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void palindrome() {
            Node* temp = head;
            Node* temp2 = tail;

            if (head == nullptr) {
                cout << "List does not exist!" << endl;
            } else if (head == tail) {
                cout << "List has only one element so it is technically a palindrome." << endl;
                return;
            } else {
                while (temp != temp2 && temp->prev != temp2) {
                    if (temp->data != temp2->data) {
                        cout << "The current List is not a palindrome." << endl;
                        return;
                    }
                    temp = temp->next;
                    temp2 = temp2->prev;
                }
                cout << "The current list ia a palindrome." << endl;
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

    doublyLinked_list list;

    list.push_front(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(1);
    list.display();
    list.palindrome();

    // list.push_front(1);
    // list.push_back(2);
    // list.push_back(3);
    // list.push_back(2);
    // list.push_back(1);
    // list.display();
    // list.palindrome();

    return 0;
}