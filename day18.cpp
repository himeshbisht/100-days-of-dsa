#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    k = k % n; // handle k > n

    // Create a new array for rotated elements
    int rotated[100];

    for(int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        cout << rotated[i] << " ";
    }

    return 0;
}