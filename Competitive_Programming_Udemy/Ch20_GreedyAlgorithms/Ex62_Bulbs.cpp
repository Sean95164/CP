#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a){
    bool change = false;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!change && a[i] == 0) {
            cnt++;
            change = !change;
        }
        else if (change && a[i] == 1) {
            cnt++;
            change = !change;
        }
    }

    return cnt;
}

int main() {
    int n = 4;
    vector<int> a = {0, 1, 0, 1};
    cout << solve(4, a) << endl;
    return 0;
}