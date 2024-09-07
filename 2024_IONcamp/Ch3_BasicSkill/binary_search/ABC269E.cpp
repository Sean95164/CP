#include <bits/stdc++.h>

using namespace std;

// check the region full or not
bool check(int a, int b, int c, int d, int num) {
    // request for system
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    // response from system
    int t;
    cin >> t;

    if (t == num) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    // Binary search to find x
    int l = 1;
    int r = n;
    while(l != r) {
        int mid = (l + r) / 2;
        int num = mid - l + 1;
        if (check(l, mid, 1, n, num)) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    int x = r;

    // Binary search to find y
    // Initialize l, r
    l = 1;
    r = n;
    while(l != r) {
        int mid = (l + r) / 2;
        int num = mid - l + 1;
        if (check(1, n, l, mid, num)) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    int y = r;

    cout << "! " << x << " " << y << endl;
    return 0;
}