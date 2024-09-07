#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> matrix) {
    int height = matrix.size();
    int width = matrix[0].size();

    vector<vector<int>> dp(height, vector<int>(width, 0));
    dp[0][0] = matrix[0][0];
    
    for (int j = 1; j < width; j++) {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }

    for (int i = 1; i < height; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }

    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            dp[i][j] = matrix[i][j] + max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[height-1][width-1];
}

int main() {
    vector<vector<int>> matrix = {
        {0, 3, 1, 1}, 
        {2, 0, 0 ,4}
    };

    cout << solve(matrix) << endl;
    return 0;
}