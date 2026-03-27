#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int mat[100][100];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int sum = 0;

    // Sum of primary diagonal
    for(int i = 0; i < m && i < n; i++) {
        sum += mat[i][i];
    }

    cout << sum;

    return 0;
}