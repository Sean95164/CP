#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> prices) {
    int days = prices.size();
    vector<vector<int>> dp(k+1, vector<int>(days, 0));

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < days; j++) {
            dp[i][j] = dp[i][j-1];
            for (int tran = 0; tran < j; tran++) {
                dp[i][j] = max(dp[i][j], dp[i-1][tran] + prices[j] - prices[tran]);
            }
        }
    }


    return dp[k][days-1];
}

int main() {
    int k = 2;
    vector<int> prices = {2, 4, 1};

    cout << maxProfit(k, prices) << endl;
    return 0;
}