#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int mat1[100][100], mat2[100][100], sum[100][100];

    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat1[i][j];
        }
    }

    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat2[i][j];
        }
    }

    // Add matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Print result matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}