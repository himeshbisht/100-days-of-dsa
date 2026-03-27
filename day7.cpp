#include <iostream>
using namespace std;

// Recursive function
int fib(int n) {
    if(n == 0) return 0;   // Base case
    if(n == 1) return 1;   // Base case
    
    return fib(n-1) + fib(n-2); // Recursive call
}

int main() {
    int n;
    cin >> n;

    cout << fib(n);

    return 0;
}