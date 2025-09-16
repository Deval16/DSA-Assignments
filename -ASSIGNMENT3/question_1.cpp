//1. Develop a menu driven program demonstrating the following operations on a Stack using array: 
// (i)  push(),   (ii)  pop(),   (iii)  isEmpty(),   (iv)  isFull(),   (v)  display(), and   (vi) peek().

#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX-1);
}

void push(int x) {
    if (isFull()) cout << "Stack Overflow\n";
    else stack[++top] = x;
}

void pop() {
    if (isEmpty()) cout << "Stack Underflow\n";
    else cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (isEmpty()) cout << "Stack is empty\n";
    else cout << "Top element: " << stack[top] << endl;
}

void display() {
    if (isEmpty()) cout << "Stack is empty\n";
    else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while(choice != 5);
    return 0;
}
