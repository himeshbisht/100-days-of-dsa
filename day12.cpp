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

    // Check if matrix is square
    if(m != n) {
        cout << "Not a Symmetric Matrix";
        return 0;
    }

    // Check symmetry
    bool symmetric = true;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] != mat[j][i]) {
                symmetric = false;
                break;
            }
        }
        if(!symmetric) break;
    }

    if(symmetric)
        cout << "Symmetric Matrix";
    else
        cout << "Not a Symmetric Matrix";

    return 0;
}