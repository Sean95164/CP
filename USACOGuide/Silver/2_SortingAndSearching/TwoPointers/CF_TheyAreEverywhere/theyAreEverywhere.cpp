#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[500] = {0};
    
    int total_nums = 0;
    
    for (int i = 0; i < n; i++) {
        if (cnt[s[i]] == 0) {
            total_nums++;
        }
        cnt[s[i]]++;
    }
    for (int i = 0; i < 500; i++) {
        cnt[i] = 0;
    }
    int l = 0, r = 0;
    int cur_nums = 0;
    int mini = INT_MAX;
    while (r < n) {
        if (cnt[s[r]] == 0) cur_nums++;
        cnt[s[r]]++;

        // cout << l << " " << r << "\n";
        // cout << cur_nums << "\n";
        while (cur_nums > total_nums) {
            if (--cnt[s[l]] == 0) cur_nums--;
            l++;
        }
        while (cnt[s[l]] > 1) {
            cnt[s[l]]--;
            l++;
        }
        if (cur_nums >= total_nums) {
            mini = min(mini, r-l+1);
        }
        r++;
    }

    cout << mini << "\n";
    return 0;
}