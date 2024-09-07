#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;


long long power(long long a, long long b) {
    long long res = 1;
    while(b) {
        if (b & 1) res *= a, res %= mod;
        a *= a; a %= mod;
        b >>= 1;
    }

    return res;
}

int locker(int n){
    if (n < 3) return n;
    else if (n % 3 == 0) {
        return power(3, n / 3) % mod;
    }
    else if (n % 3 == 1) {
        n -= 4;
        return (4*power(3, n / 3)) % mod;
    }
    else {
        n -= 2;
        return (2*power(3, n / 3)) % mod;
    }
}

int main() {
    int n;
    cin >> n;
    cout << locker(n) << endl;
    return 0;
}