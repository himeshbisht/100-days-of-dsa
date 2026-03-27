#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int left = 0;
    int right = s.length() - 1;
    bool isPalindrome = true;

    while(left < right) {
        if(s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if(isPalindrome)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}