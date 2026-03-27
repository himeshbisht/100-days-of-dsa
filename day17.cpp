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

    int maxVal = arr[0]; // Initialize max with first element
    int minVal = arr[0]; // Initialize min with first element

    // Traverse array to find max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) maxVal = arr[i];
        if(arr[i] < minVal) minVal = arr[i];
    }

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    return 0;
}