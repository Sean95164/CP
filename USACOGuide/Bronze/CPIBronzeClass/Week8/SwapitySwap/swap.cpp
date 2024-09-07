#include <bits/stdc++.h>

using namespace std;

int n, K, a1, a2, b1, b2;

int next(int x) {
    if (a1 <= x && x <= a2) {
        x = a1 + a2 - x;
    }
    if (b1 <= x && x <= b2) {
        x = b1 + b2 - x;
    }

    return x;
}
int main() {
    // freopen("swap.in", "r", stdin);
    // freopen("swap.out", "w", stdout);
    
    cin >> n >> K >> a1 >> a2 >> b1 >> b2;
    vector<int> res(n+1);
    for (int i = 1; i <= n; i++) {
        int times = 1, cur = next(i);
        while(cur != i) {
            times++;
            cur = next(cur);
        }

        int k = K % times;
        for (int j = 0; j < k; j++) {
            cur = next(cur);
        }

        res[cur] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}