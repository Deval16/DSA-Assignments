// Write a program to implement a stack using (a) Two queues and (b) One Queue.
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    // Push operation (costly)
    void push(int x) {
        // Step 1: Push to empty q2
        q2.push(x);

        // Step 2: Push all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    // Pop operation
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }

    // Top operation
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check if empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "Top: " << s.top() << endl; // 20
    return 0;
}




//B part
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate previous elements to the back
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "Top: " << s.top() << endl; // 20
    return 0;
}
