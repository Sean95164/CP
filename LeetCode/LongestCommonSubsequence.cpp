#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1, vector<int>(n2));
    // init
    dp[0][0] = text1[0] == text2[0];
    for (int j = 1; j < n2; j++) {
        if (dp[0][j-1] == 1) {
            dp[0][j] = dp[0][j-1];
        }
        else {
            dp[0][j] = (text1[0] == text2[j]);
        }
        
    }
    for (int i = 1; i < n1; i++) {
        if (dp[i-1][0] == 1) {
            dp[i][0] = dp[i-1][0];
        }
        else {
            dp[i][0] = (text1[i] == text2[0]);
        }
    }

    for (int i = 1; i < n1; i++) {
        for (int j = 1; j < n2; j++) {
            if (text1[i] == text2[j]) {
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + 1));
            }
            else {
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
            
        }
    }

    // for (int i = 0; i < n1; i++) {
    //     for (int j = 0; j < n2; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n1-1][n2-1];
}

int main() {
    string text1 = "aa";
    string text2 = "aaa";

    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}