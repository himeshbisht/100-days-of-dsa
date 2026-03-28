#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int n, m;
    cin >> n;

    int stackArr[MAX];
    int top = -1;

    // Push
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stackArr[++top] = x;
    }

    // Pop m times
    cin >> m;
    for(int i = 0; i < m; i++) {
        if(top != -1)
            top--;
    }

    // Display
    for(int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";

    return 0;
}