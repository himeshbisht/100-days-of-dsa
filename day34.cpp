#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node* &top, int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop(Node* &top) {
    if(top == NULL) return 0;
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int main() {
    string exp;
    getline(cin, exp);

    stringstream ss(exp);
    string token;

    Node* top = NULL;

    while(ss >> token) {
        if(isdigit(token[0])) {
            push(top, stoi(token));
        }
        else {
            int b = pop(top);
            int a = pop(top);

            if(token == "+") push(top, a + b);
            else if(token == "-") push(top, a - b);
            else if(token == "*") push(top, a * b);
            else if(token == "/") push(top, a / b);
        }
    }

    cout << pop(top);
    return 0;
}