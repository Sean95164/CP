#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i*i <= n; i++) {
        dp[i*i] = 1;
    }    

    
    for (int i = 2; i <= n; i++) {
        if (dp[i] != 0) continue;

        int curMin = INT_MAX;
        for (int j = 1; j*j < i; j++) {
            curMin = min(curMin, dp[i-j*j] + 1);
        }
        dp[i] = curMin;
    }

    return dp[n];
}

int main() {
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}