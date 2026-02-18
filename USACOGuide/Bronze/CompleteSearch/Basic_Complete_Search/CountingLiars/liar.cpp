#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<char> sym(n);
    vector<int> nums(n);
    vector<int> seg;
    seg.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> sym[i] >> nums[i];
        seg.push_back(nums[i]);
    }
    seg.push_back(1e9+1);
    sort(seg.begin(), seg.end());
    int ans = INT_MAX;
    for (int i = 0; i < n+1; i++) {
        int e1 = seg[i], e2 = seg[i+1];
        // cout << "[" << e1 << ", " << e2 << "):\n";
        // count for liar
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((sym[j] == 'G' && e2 <= nums[j]) || 
                (sym[j] == 'L' && e1 > nums[j])) {
                cnt++;
            }
        }
        // cout <<  cnt << "\n";
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}