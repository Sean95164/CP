#include<bits/stdc++.h>
using namespace std;

long long solve(int n, vector<int> a){
    sort(a.begin(), a.end());
    a.push_back(INT_MAX);
    vector<pair<int, long long>> pr;

    int num = a[0];
    int l = 0 , r = 0;
    while(r <= n) {
        if (a[r] != a[l]) {
            pr.push_back({a[l], (r-l) * a[l]});
            l = r;
        }
        r++;
    }

    int k = pr.size();
    vector<long long> dp(k);
    
    dp[0] = pr[0].second;
    for (int i = 1; i < k; i++) {
        if (pr[i].first - pr[i-1].first == 1) {
            dp[i] = max(dp[i-1], pr[i].second + dp[i-2]);
        }
        else {
            dp[i] = dp[i-1] + pr[i].second;
        }
    }

    return dp[k-1];
}

int main() {
    int n = 8;
    vector<int> a = {88, 48, 13, 74, 85, 26, 86, 50};

    cout << solve(n, a) << endl;
    return 0;
}