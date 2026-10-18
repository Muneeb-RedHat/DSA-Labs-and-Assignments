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

        void push_between(int n, int val) {
            Node* newNode = new Node(val);
            Node* temp = head;
            if (head == nullptr) {
                cout << "The list is empty!" << endl;
            } else {
                for(int i = 0; i < n - 1; i++) {
                    if (temp->next == nullptr) {
                        cout << "use push back function!" <<endl;
                        delete newNode;
                        newNode = nullptr;
                        return;
                    }
                    temp = temp->next;
                }
                newNode->next = temp->next;
                newNode->prev = temp;
                (temp->next)->prev = newNode;
                temp->next = newNode;
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
                } else {
                    head->prev = nullptr;
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
                Node* temp = tail;
                tail = tail->prev;
                delete temp;
                tail->next = nullptr;
            }
        }

        // void search(string val) {
        //     Node* temp = head;
        //     while(temp != nullptr) {
        //         if (temp->data == val) {
        //             cout<< "Required Id is found!" << endl;
        //             return;
        //         }
        //         temp = temp->next;
        //     }
        //     cout << "Required Id not found!" << endl;

        // }

        // void pop_between(int val){
        //     if (head == nullptr) {
        //         cout << "List is empty!" << endl;
        //     } else if (head->data == val){
        //         pop_front();
        //         return;
        //     } else {
        //         Node* temp = head;
        //     while(temp->next != nullptr) {
        //         if (temp->next->data == val) {
        //             Node* temp2;
        //             temp2 = temp->next;
        //             if(temp2 == tail) {
        //                 pop_back();
        //                 return;
        //             }
        //             temp->next = temp2->next;
        //             delete temp2;
        //             temp2 = nullptr;void pop_back() {
        //     if (head == nullptr) {
        //         cout << "List is empty!" << endl;
        //     } else if (head == tail){
        //             delete head;
        //             head = nullptr;
        //             tail = nullptr;
        //     } else {
        //         Node* temp = tail;
        //         tail = tail->prev;
        //         delete temp;
        //         tail->next = nullptr;
        //     }
        // }
        //     }
        //     }
        // }

        // void count() {
        //     Node* temp = head;
        //     int count = 0;
        //     while(temp != nullptr) {
        //         count++;
        //         temp = temp->next;

        //     }
        //     cout << "The no. of Items in this list are " << count << "." << endl;
        // }

        // void display(){
        //     Node* temp = head;
        //     while(temp != nullptr) {
        //         cout << temp->data << "->";
        //         temp = temp->next;
        //     }
        //     cout << "Null" << endl;
        // }
};

int main () {

    doublyLinked_list list;

    list.push_front(500);
    list.push_front(400);
    list.push_front(300);
    list.push_front(200);
    list.push_front(100);
    list.push_back(900);
    list.push_back(777);
    list.pop_front();
    list.pop_back();
    list.push_between(3,777999);

    Node* temp = list.head;
    for(int i = 0; i < 6; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}