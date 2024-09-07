#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll x, ll y, ll p, ll q, ll value) { 
    return (p * value >= x) && (q * value - p * value >= y - x);
}

long long solve(int x,int y,int p, int q){
    int l = 0;
    int r = 1e9;

    
    if (!check(x, y, p, q, r)) {
        return -1;
    }

    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (check(x, y, p, q, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    long long total = (long long) q * (long long) ans;
    total -= y;
    return total;
}

int main() {
    cout << solve(7, 14, 3, 8) << endl;
    cout << solve(5, 6, 1, 1) << endl;
    return 0;
}