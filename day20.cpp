#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> prefixSumFreq;
    int sum = 0, count = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) count++;                // subarray from 0 to i
        if(prefixSumFreq.find(sum) != prefixSumFreq.end())
            count += prefixSumFreq[sum];     // add frequency of same sum so far

        prefixSumFreq[sum]++;
    }

    cout << count;

    return 0;
}