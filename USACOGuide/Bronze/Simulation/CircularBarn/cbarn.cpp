#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> r(n);
    
    // i'th door requires r[i] cows
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int mini = INT_MAX;
    // open i'th door
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        
        // count each cows movement
        for (int j = 0; j < n; j++) {
            int walk;
            if (j >= i) {
                walk = j-i;
            }
            else {
                walk = n - (i-j);
            }
            cnt += walk * r[j];
        }
    
        mini = min(mini, cnt);
    }

    cout << mini << "\n";
    return 0;
}