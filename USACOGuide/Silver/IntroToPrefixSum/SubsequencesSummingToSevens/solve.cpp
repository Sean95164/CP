#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i+1] = (prefix[i] + arr[i]) % 7;
    }

    vector<int> last_found(7, -1);
    
    int ans = 0;
    for (int i = 0; i < prefix.size(); i++) {
        if (last_found[prefix[i]] == -1) {
            last_found[prefix[i]] = i;
        }
        else {
            ans = max(ans, i - last_found[prefix[i]]);
        }
    }

    cout << ans << endl;
    return 0;
}