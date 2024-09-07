#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

vector<int> solve(int n,int m, vector<int> a, vector<int> b) {

    vector<int> ans(m);

    int g = 0;
    for (int i = 1; i < n; i++) {
        a[i] = a[i] - a[0];
        g = gcd(g, a[i]);
    }

    for (int i = 0; i < m; i++) {
        ans[i] = gcd(a[0] + b[i], g);
    }
    return ans;
}

int main() {
    vector<int> ans = solve(4,4, {1,25,121,169}, {1,2,7,23});
    for (auto x : ans) {
        cout << x << ", ";
    }
    cout << endl;
}