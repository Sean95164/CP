#include <bits/stdc++.h>

using namespace std;
int solve(int n,int m, vector<int> a){
    // pigeonhole principle
    if (n > m) return 0;

    // Because m <= 1000, and if n > m, it will be 0.
    // which means when use brute force, n <= 1000, it's ok
    // for O(N^2) solution
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long tmp = abs(a[i] - a[j]) % m;
            ans = (ans * tmp) % m;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(n, m, a) << "\n";
    return 0;
}