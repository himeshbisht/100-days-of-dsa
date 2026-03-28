#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int n, m;
    cin >> n;

    int q[MAX];
    int front = 0, rear = -1;

    // Enqueue
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }

    cin >> m;

    // Dequeue m times
    for(int i = 0; i < m; i++) {
        if(front != (rear + 1) % MAX)
            front = (front + 1) % MAX;
    }

    // Display
    int i = front;
    while(i != (rear + 1) % MAX) {
        cout << q[i] << " ";
        i = (i + 1) % MAX;
    }

    return 0;
}