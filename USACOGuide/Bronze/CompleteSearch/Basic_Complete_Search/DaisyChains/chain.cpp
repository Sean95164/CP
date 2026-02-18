#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int total = accumulate(p.begin() + i, p.begin() + j, 0);
            double ave = (double) total / (j-i);
        
            for (int k = i; k < j; k++) {
                if (p[k] == ave) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}