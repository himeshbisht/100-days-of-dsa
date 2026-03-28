#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Example operations
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    dq.pop_front();
    dq.pop_back();

    dq.push_front(40);

    // Display
    for(int x : dq)
        cout << x << " ";

    return 0;
}