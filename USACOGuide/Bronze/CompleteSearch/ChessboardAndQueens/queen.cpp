#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8;

char board[SIZE][SIZE];

bool check(int row, int col) {
    if (board[row][col] == '*') {
        return false;
    }

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    int i = row-1, j = col-1;
    while(i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i -= 1;
        j -= 1;
    }

    i = row - 1, j = col + 1;
    while(i >= 0 && j < SIZE) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i -= 1;
        j += 1;
    }

    return true;
}

void queen(int row, int col, int &ans) {
    if (row == SIZE) {
        ans++;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (check(row, i)) {
            board[row][i] = 'Q';
            queen(row+1, 0, ans);
            board[row][i] = '.';
        }
    }

    return;
}

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    
    queen(0, 0, ans);

    cout << ans << endl;
    return 0;
}