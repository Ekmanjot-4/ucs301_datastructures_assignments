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

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }

    void enqueue(int x) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    void display() {
        int i = front;
        for (int c = 0; c < size; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    int getSize() { return size; }
    int getFront() { return arr[front]; }
};

int main() {
    int n, x;
    cin >> n;
    Queue q(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    int half = n / 2;
    int first[half], second[half];
    for (int i = 0; i < half; i++) first[i] = q.dequeue();
    for (int i = 0; i < half; i++) second[i] = q.dequeue();

    for (int i = 0; i < half; i++) {
        q.enqueue(first[i]);
        q.enqueue(second[i]);
    }

    q.display();
    return 0;
}
