#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) return;
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackOneQueue s;
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
