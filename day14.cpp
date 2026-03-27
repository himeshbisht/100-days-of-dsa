#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mat[100][100];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    bool isIdentity = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && mat[i][j] != 1) {       // Diagonal elements must be 1
                isIdentity = false;
                break;
            }
            if(i != j && mat[i][j] != 0) {       // Non-diagonal elements must be 0
                isIdentity = false;
                break;
            }
        }
        if(!isIdentity) break;
    }

    if(isIdentity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}