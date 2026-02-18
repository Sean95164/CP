#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    long long total = k+1;

    for (int i = 1; i < n; i++) {
        total += min(k+1, d[i]-d[i-1]);
    }
    cout << total << "\n";
    return 0;
}