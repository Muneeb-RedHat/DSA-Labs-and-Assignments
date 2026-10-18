#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void josephus(int N, int M)
{
    if (N <= 0) { cout << "Invalid N." << endl; return; }
    if (M < 0)  { cout << "Invalid M." << endl; return; }

    Node* head = new Node(1);
    Node* last = head;
    for (int i = 2; i <= N; i++)
    {
        last->next = new Node(i);
        last = last->next;
    }
    last->next = head; // circular

    cout << "Elimination order: ";

    Node* current = last; // predecessor of person 1
    int size = N;

    while (size > 1)
    {
        int steps = M % size; // skip full laps
        for (int i = 0; i < steps; i++)
            current = current->next;

        Node* victim = current->next;
        cout << victim->data << " ";

        current->next = victim->next;
        delete victim;
        size--;
    }

    cout << endl;
    cout << "Winner: " << current->data << endl;

    delete current; // dispose of the last cell
}

int main()
{
    int N, M;

    cout << "Enter N: ";
    cin >> N;

    cout << "Enter M: ";
    cin >> M;

    josephus(N, M);

    return 0;
}