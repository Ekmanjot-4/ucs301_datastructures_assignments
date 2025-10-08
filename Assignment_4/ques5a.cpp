#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackTwoQueues s;
    int n, x, ch;
    while (1) {
        cout << "1.Push 2.Pop 3.Top 4.Display 5.Exit\n";
        cin >> ch;
        if (ch == 5) break;
        switch(ch) {
            case 1: cin >> x; s.push(x); break;
            case 2: s.pop(); break;
            case 3: cout << s.top() << endl; break;
            case 4: s.display(); break;
        }
    }
    return 0;
}
