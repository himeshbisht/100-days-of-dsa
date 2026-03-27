#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];

    // Input array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> freq;

    // Count frequency
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequency
    for(auto it : freq) {
        cout << it.first << ":" << it.second << " ";
    }

    return 0;
}