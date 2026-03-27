#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Read array size

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read array elements
    }

    int k;
    cin >> k; // Read key to search

    int comparisons = 0;
    int index = -1; // To store the index if found

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Comparisons = " << comparisons << endl;

    return 0;
}