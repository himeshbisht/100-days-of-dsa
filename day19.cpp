#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the array for two-pointer approach
    sort(arr, arr + n);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int a = 0, b = 0;

    while(left < right) {
        int sum = arr[left] + arr[right];

        // Update pair if current sum is closer to zero
        if(abs(sum) < minSum) {
            minSum = abs(sum);
            a = arr[left];
            b = arr[right];
        }

        // Move pointers
        if(sum < 0)
            left++;    // Need larger sum
        else
            right--;   // Need smaller sum
    }

    cout << a << " " << b;

    return 0;
}