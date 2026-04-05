#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << -1 << " ";
            return;
        }
        cout << front->data << " ";
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) rear = NULL;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if (op == "ENQUEUE") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else {
            q.dequeue();
        }
    }
}