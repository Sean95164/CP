#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if ((x[i] == x[j] || x[j] == x[k] || x[k] == x[i]) &&
                    (y[i] == y[j] || y[j] == y[k] || y[k] == y[i])) {
                        int area = max(abs(x[i]-x[j]), abs(x[j]-x[k])) * max(abs(y[i]-y[j]), abs(y[j]-y[k]));
                        // cout << i << j << k << "\n";
                        // cout << area << "\n";
                        maxi = max(area, maxi);
                    }
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}