#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;

    vector<int> kind(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> kind[i];
    }

    vector<int> pre1(n+1, 0);
    vector<int> pre2(n+1, 0);
    vector<int> pre3(n+1, 0);

    for (int i = 1; i <= n; i++) {
        pre1[i] = pre1[i-1];
        pre2[i] = pre2[i-1];
        pre3[i] = pre3[i-1];
        if (kind[i] == 1) {
            pre1[i]++;
        }
        else if (kind[i] == 2) {
            pre2[i]++;
        }
        else {
            pre3[i]++;
        }
    }

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << pre1[b] - pre1[a-1] << " " << pre2[b] - pre2[a-1] << " " << pre3[b] - pre3[a-1] << "\n"; 
    }
    return 0;
}