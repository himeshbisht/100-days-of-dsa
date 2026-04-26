// 2. Lower Bound and Upper Bound using Binary Search
#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n, x;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;

    cout << lowerBound(arr, n, x) << " " << upperBound(arr, n, x);

    return 0;
}