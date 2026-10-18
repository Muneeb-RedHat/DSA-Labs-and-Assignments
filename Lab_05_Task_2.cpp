#include <iostream>
using namespace std;
const int SIZE = 100;

class Queue {

    int arr[SIZE];
    int front, rear, count;
public:
    Queue() { front = 0; rear = -1; count = 0; }
    bool isEmpty() { return count == 0; }
    void enqueue(int x) {
        rear = (rear + 1) % SIZE;  
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        int x = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return x;
    }
};

int main() {

    Queue q;
    int n, x, evenCount = 0;

    cout << "How many people? ";
    cin >> n;
    
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
        if (x % 2 == 0)
            evenCount++;
    }

    int served = 0;
    cout << "Served Order: ";
    while (served < evenCount) {
        int person = q.dequeue();
        if (person % 2 == 0) {
            cout << person << " ";   
            served++;
        } else {
            q.enqueue(person);     
        }
    }
    cout << endl;

    cout << "Remaining Queue: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}