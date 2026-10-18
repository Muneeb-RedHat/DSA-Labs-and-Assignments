#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        string data;
        Node* next;

        Node(string val) {
            data = val;
            next = nullptr;
        }
};

class Linked_list {
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        void push_front(string val){
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(string val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void push_between(int n, string val) {
            if (n <= 0) {
                cout << "Invalid position!" << endl;
                return;
            }

            if (head == nullptr) {
                if (n == 1) {
                    push_front(val);
                } else {
                    cout << "The list is empty!" << endl;
                }
                return;
            }

            if (n == 1) {
                push_front(val);
                return;
            }

            Node* newNode = new Node(val);
            Node* temp = head;

            for (int i = 1; i < n - 1; i++) {
                if (temp->next == nullptr) {
                    cout << "use push back function!" << endl;
                    delete newNode;
                    newNode = nullptr;
                    return;
                }
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == tail) {
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
            } else if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }

                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }

        void search(string val) {
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

        void pop_between(string val){
            if (head == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }

            if (head->data == val) {
                pop_front();
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->next->data == val) {
                    Node* removeNode = temp->next;
                    temp->next = removeNode->next;

                    if (removeNode == tail) {
                        tail = temp;
                    }

                    delete removeNode;
                    removeNode = nullptr;
                    return;
                }
                temp = temp->next;
            }

            cout << "Required Id not found!" << endl;
        }

        void count() {
            Node* temp = head;
            int count = 0;
            while(temp != nullptr) {
                count++;
                temp = temp->next;

            }
            cout << "The no. of Items in this list are " << count << "." << endl;
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
    
    list.push_back("Perfect");
    list.push_back("Believer");
    list.push_back("Shape of you");
    list.push_back("Faded");
    
    list.display();

    list.push_front("Attention");
    list.display();

    list.push_between(3,"Memories");
    list.display();

    list.push_back("Havana");
    list.display();

    list.search("Believer");
    list.search("Despacito");

    list.pop_between("Memories");
    list.display();
    list.count();

    return 0;
}