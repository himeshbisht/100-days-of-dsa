#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (mp.find(sum) != mp.end())
            maxLen = max(maxLen, i - mp[sum]);
        else
            mp[sum] = i;
    }

    cout << maxLen;
}