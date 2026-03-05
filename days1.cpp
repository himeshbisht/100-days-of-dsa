#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // size of the array

    int arr[n + 1];  // +1 to make space for new element
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // input array elements
    }

    int pos, x;
    cin >> pos >> x;  // position (1-based) and element to insert

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos - 1] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}