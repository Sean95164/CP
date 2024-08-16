#include <bits/stdc++.h>

using namespace std;

int solve(int L, int R) {
    if (L - 1 + L < R) {
        return -1;
    }
    int max_num = L - 1 + L;
    int ans = min(max_num, R);
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << "\n";
    return 0;
}