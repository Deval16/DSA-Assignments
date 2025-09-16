//. Write a program that checks if an expression has balanced parentheses.  


#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c=='(' || c=='{' || c=='[') s.push(c);
        else if (c==')' || c=='}' || c==']') {
            if (s.empty()) return false;
            if ((c==')' && s.top()!='(') ||
                (c=='}' && s.top()!='{') ||
                (c==']' && s.top()!='[')) return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    cout << (isBalanced(exp) ? "Balanced" : "Not Balanced");
}

