#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(int a,int b){
    vector<int> factor;
    for (int i = 1; i*i <= a; i++) {
        if (a % i == 0) {
            factor.push_back(i);
            factor.push_back(a / i);
        }
    }

    sort(factor.begin(), factor.end());
    int ans = -1;
    for (auto x : factor) {
        if (gcd(x, b) == 1) {
            ans = x;
        }
    }

    return ans;
}

int main() {
    int a = 30;
    int b = 12;
    cout << solve(a, b) << endl;
}