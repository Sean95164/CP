#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (x - a[i] < 0) {
            break;
        }
        x -= a[i];
        total++;
    }

    cout << total << "\n";
    return 0;
}