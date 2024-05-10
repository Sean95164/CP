#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;
const int sz = 2;

struct Mat {
    long long m[sz][sz];
    Mat() {
        memset(m, 0, sizeof(m));
    }

    void identity() {
        for (int i = 0; i < sz; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator* (Mat a) {
        Mat res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }

        return res;
    }
};

long long fab(int n) {
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    n -= 2;
    while (n) {
        if (n & 1) res = res * T;
        T = T * T;
        n >>= 1;
    }

    return (res.m[0][0] + res.m[0][1]) % mod;
}

int fibSum(int n,int m){
    long long ans = 0;
    for (int i = n; i <= m; i++) {
        ans += fab(i);
        ans %= mod;
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << fibSum(n ,m) << endl;
    // cout << fab(5) << endl;
    return 0;
}