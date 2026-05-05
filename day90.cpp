#include <stdio.h>
#include <algorithm>
using namespace std;

int isValid(int arr[], int n, int m, int maxPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }
    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = *max_element(arr, arr + n);
    int high = 0;
    for (int i = 0; i < n; i++) high += arr[i];

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
}