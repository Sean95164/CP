#include<bits/stdc++.h>
using namespace std;

#define sz 9

bool valid(vector<vector<int>> ans, int x, int y, int no) {
    // check for row and column
    for (int k = 0; k < sz; k++) {
        if (ans[k][y] == no || ans[x][k] == no) {
            return false;
        }
    }

    // check for region
    int si = (x/3)*3;
    int sj = (y/3)*3;

    for (int i = si; i < si+3; i++) {
        for (int j = sj; j<sj+3; j++) {
            if (ans[i][j] == no) {
                return false;
            }
        }
    }

    return true;
}

bool __solve(vector<vector<int>> &ans, int i, int j) {
    // base case
    if (i == sz) {
        return true;
    }

    // rec case
    if (j == sz) {
        return __solve(ans, i + 1, 0);
    }

    if (ans[i][j] != 0) {
        return __solve(ans, i, j + 1);
    }

    for (int no = 1; no <= 9; no++) {
        if (valid(ans, i, j, no)) {
            ans[i][j] = no;
            if (__solve(ans, i, j + 1)) return true;
        }
    }

    ans[i][j] = 0;
    return false;
}

vector<vector<int>> solve(vector<vector<int>> matrix) {
    __solve(matrix, 0 ,0);
    return matrix;
}

int main() {
    vector<vector<int>> mat = {
        {0, 2, 0, 5, 0, 1, 0, 9, 0},
        {8, 0, 0, 2, 0, 3, 0, 0, 6},
        {0, 3, 0, 0, 6, 0, 0, 7, 0},
        {0, 0, 1, 0, 0, 0, 6, 0, 0},
        {5, 4, 0, 0, 0, 0, 0, 1, 9},
        {0, 0, 2, 0, 0, 0, 7, 0, 0},
        {0, 9, 0, 0, 3, 0, 0, 8, 0},
        {2, 0, 0, 8, 0, 4, 0, 0, 7},
        {0, 1, 0, 9, 0, 7, 0, 6, 0}
    };

    vector<vector<int>> ans = solve(mat);
    for (auto row : ans) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}