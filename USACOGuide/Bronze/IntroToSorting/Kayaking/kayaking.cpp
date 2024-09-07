#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);


    int n;
    cin >> n;

    vector<int> weight(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    int ans = INT_MAX;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            vector<int> s;

            for (int k = 0; k < 2 * n; k++) {
                if (k != i && k != j) {
                    s.push_back(weight[k]);
                }
            }

            int temp = 0;
            for (int k = 0; k < s.size(); k+=2) {
                temp += (s[k+1] - s[k]);
            }

            ans = min(ans, temp);
        }
    }

    cout << ans << endl;
    return 0;
}