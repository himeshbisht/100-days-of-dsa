#include <iostream>
using namespace std;

// Recursive function
int power(int a, int b) {
    if(b == 0) return 1;      // Base case: a^0 = 1
    return a * power(a, b-1); // Recursive call
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << power(a, b);

    return 0;
}