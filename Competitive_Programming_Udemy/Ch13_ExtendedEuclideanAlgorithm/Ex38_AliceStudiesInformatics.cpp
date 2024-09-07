#include <bits/stdc++.h>

using namespace std;

#define ll long long

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(int l,int r,int x,int y){
    if (y % x != 0) {
        return 0;
    }

    int ans = 0;
    int tmp = y / x;
    l /= x;
    r /= x;

    for (int i = 1; i*i <= tmp; i++) {
        if (tmp % i == 0) {
            int c = i;
            int d = tmp / c;
            if (gcd(c, d) == 1 && (c >= l && c <= r) && 
                                  (d >= l && d <= r)) {
                ans++;
                if (c != d) ans++;
            }
        }

        
    }

    return ans;
}

int main() {
    cout << solve(2783175, 6882425, 21575, 887832825) << endl;
    return 0;
}