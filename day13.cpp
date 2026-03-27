#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int mat[100][100];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right) {
        // Traverse top row
        for(int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        // Traverse rightmost column
        for(int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // Traverse bottom row (if remaining)
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        // Traverse leftmost column (if remaining)
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }

    return 0;
}