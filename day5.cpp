#include <iostream>
using namespace std;

int main() {
    int p, q;

    // Input size of first log
    cin >> p;
    int a[p];

    // Input first sorted array
    for(int i = 0; i < p; i++) {
        cin >> a[i];
    }

    // Input size of second log
    cin >> q;
    int b[q];

    // Input second sorted array
    for(int i = 0; i < q; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;

    // Merge both arrays
    while(i < p && j < q) {
        if(a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
        }
    }

    // Print remaining elements of first array
    while(i < p) {
        cout << a[i] << " ";
        i++;
    }

    // Print remaining elements of second array
    while(j < q) {
        cout << b[j] << " ";
        j++;
    }

    return 0;
}