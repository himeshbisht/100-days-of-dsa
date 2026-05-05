#include <stdio.h>
#include <algorithm>
using namespace std;

int canPlace(int arr[], int n, int k, int dist) {
    int cows = 1, last = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            cows++;
            last = arr[i];
        }
    }
    return cows >= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    int low = 1, high = arr[n-1] - arr[0], ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);
}