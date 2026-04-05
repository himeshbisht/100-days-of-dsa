#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2*i+1 < n && v[i] > v[2*i+1]) {
            cout << "NO";
            return 0;
        }
        if (2*i+2 < n && v[i] > v[2*i+2]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}