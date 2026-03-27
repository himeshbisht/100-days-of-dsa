#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the array
    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Two-pointer approach to reverse the array
    int left = 0, right = n - 1;
    while (left < right) {
        // Swap elements at left and right pointers
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}