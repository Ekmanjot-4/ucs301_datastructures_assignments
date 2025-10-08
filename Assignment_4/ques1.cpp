#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;
public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cin >> cap;
    Queue q(cap);
    int ch, x;
    while (1) {
        cout << "1.Enqueue 2.Dequeue 3.IsEmpty 4.IsFull 5.Peek 6.Display 7.Exit\n";
        cin >> ch;
        if (ch == 7) break;
        switch(ch) {
            case 1: cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Yes\n" : "No\n"); break;
            case 4: cout << (q.isFull() ? "Yes\n" : "No\n"); break;
            case 5: q.peek(); break;
            case 6: q.display(); break;
        }
    }
    return 0;
}
