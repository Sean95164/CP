#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;
    vector<bool> broken(n+1, false);
    int x;
    for (int i = 0; i < b; i++) {
        cin >> x;
        broken[x] = true;
    }
    vector<int> psum(n+2);
    psum[0] = 0;
    for (int i = 0; i < n+1; i++) {
        psum[i+1] = psum[i] + broken[i]; 
    }

    int mini = INT_MAX;
    for (int i = 1; i <= n-k+1; i++) {
        mini = min(mini, psum[i+k]-psum[i]);
    }

    cout << mini << "\n";
    return 0;
}