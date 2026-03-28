#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int x) {
    if(top == MAX - 1)
        cout << "Stack Overflow\n";
    else
        stackArr[++top] = x;
}

void pop() {
    if(top == -1)
        cout << "Stack Underflow\n";
    else
        cout << stackArr[top--] << endl;
}

void display() {
    if(top == -1)
        cout << "Stack Empty\n";
    else {
        for(int i = top; i >= 0; i--)
            cout << stackArr[i] << " ";
        cout << endl;
    }
}

int main() {
    int n, op, val;
    cin >> n;

    while(n--) {
        cin >> op;
        if(op == 1) {
            cin >> val;
            push(val);
        }
        else if(op == 2)
            pop();
        else if(op == 3)
            display();
    }

    return 0;
}