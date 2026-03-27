#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];

    // Input array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Edge case
    if(n == 0) return 0;

    // j points to index of unique elements
    int j = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for(int i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}