#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int n;
    cin >> n;

    int queue[MAX];
    int front = 0, rear = -1;

    // Enqueue
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        queue[++rear] = x;
    }

    // Display
    for(int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    return 0;
}