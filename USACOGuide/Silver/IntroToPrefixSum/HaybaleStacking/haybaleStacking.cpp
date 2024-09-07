#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("stacking.in", "r", stdin);
    // freopen("stacking.out", "w", stdout);

    int n, k;

    cin >> n >> k;
    vector<int> diff(n+1);

    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        a--;
        b--;
        diff[a]++;
        diff[b+1]--;
    }

    vector<long long> prefix(n);

    int total = 0;
    for (int i = 0; i < prefix.size(); i++) {
        total += diff[i];
        prefix[i] = total;
    }
    
    sort(prefix.begin(), prefix.end());

    cout << prefix[n/2] << endl;
    return 0;
}