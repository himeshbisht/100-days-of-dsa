#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Read array size

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read array elements
    }

    int pos;
    cin >> pos;  // Read 1-based position to delete

    // Check if position is valid
    if (pos < 1 || pos > n) {
        cout << "Invalid position" << endl;
        return 0;
    }

    // Shift elements left from position
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}