#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> &w, int index, long long sum1, long long sum2) {
    if (index == w.size()) {
        return abs(sum1 - sum2);
    }

    return min(solve(w, index + 1, sum1 + w[index], sum2), solve(w, index + 1, sum1, sum2 + w[index]));
}

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << solve(w, 0, 0, 0) << endl;
    return 0;
}