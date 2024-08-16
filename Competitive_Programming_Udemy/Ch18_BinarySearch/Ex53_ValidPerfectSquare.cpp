#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int num) {
    int l = 1;
    int r = num;

    while(l <= r) {
        int mid = (l + r) / 2;
        if (mid*mid == num) {
            return true;
        }
        else if (num < mid*mid) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }


    return false;
}

int main() {
    int num;
    cin >> num;

    cout << isPerfectSquare(num) << "\n";

    return 0;
}