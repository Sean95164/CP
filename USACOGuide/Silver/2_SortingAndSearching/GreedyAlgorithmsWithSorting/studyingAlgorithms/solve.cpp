#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time + a[i] > x) {
            break;
        }    
        ans++;
        time += a[i];
    }

    cout << ans << "\n";
    return 0;
}