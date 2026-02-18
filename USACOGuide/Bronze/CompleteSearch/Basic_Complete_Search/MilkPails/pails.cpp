#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;
    
    int maxi = 0;
    for (int i = 0; i <= m; i++) {
        if (x * i > m) break;
        for (int j = 0; j <= m; j++) {
            if (x * i + y * j > m) break;
            int n = x * i + y * j;
            if (n > maxi) {
                maxi = n;
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}