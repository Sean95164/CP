#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> t(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }

    int low = 0, high = 1e9;
    for (int i = n-1; i >= 0; i--) {
        if (t[i] == "none") {
            low = max(low, a[i]);
            high = min(high, b[i]);
        }
        else if (t[i] == "on") {
            low -= b[i];
            high -= a[i];
            low = max(0, low);
        }
        else if (t[i] == "off") {
            low += a[i];
            high += b[i];
        }
    }

    cout << low << " " << high << "\n";

    low = 0, high = 1e9;
    for (int i = 0; i < n; i++) {
        if (t[i] == "none") {
            low = max(a[i], low);
            high = min(b[i], high);
        }
        else if (t[i] == "on") {
            low += a[i];
            high += b[i];
        }
        else if (t[i] == "off") {
            low -= b[i];
            high -= a[i];
            low = max(0, low);
        }
    }
    cout << low << " " << high << "\n";
    return 0;
}