#include <iostream>
using namespace std;

class LinkedList
{
private:

    struct Node
    {
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = NULL;
        }
    };

    Node* header;

public:

    // Constructor
    LinkedList()
    {
        header = new Node(0);   // Header node
        header->next = NULL;
    }

    // Destructor
    ~LinkedList()
    {
        Node* current = header;

        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // a. Return size of linked list
    int size()
    {
        int count = 0;
        Node* current = header->next;

        while (current != NULL)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    // b. Print linked list
    void print()
    {
        Node* current = header->next;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // c. Test whether x is contained in the list
    bool contains(int x)
    {
        Node* current = header->next;

        while (current != NULL)
        {
            if (current->data == x)
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // d. Add x if it is not already contained
    void add(int x)
    {
        if (contains(x))
        {
            return;
        }

        Node* newNode = new Node(x);

        // Insert at beginning
        newNode->next = header->next;
        header->next = newNode;
    }

    // e. Remove x if it is contained
    void remove(int x)
    {
        Node* previous = header;
        Node* current = header->next;

        while (current != NULL)
        {
            if (current->data == x)
            {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }
};


// Testing the class
int main()
{
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(20);     // Will not be added because 20 already exists

    cout << "Linked List: ";
    list.print();

    cout << "Size: " << list.size() << endl;

    if (list.contains(20))
        cout << "20 is present" << endl;
    else
        cout << "20 is not present" << endl;

    list.remove(20);

    cout << "After removing 20: ";
    list.print();

    cout << "Size: " << list.size() << endl;

    return 0;
}