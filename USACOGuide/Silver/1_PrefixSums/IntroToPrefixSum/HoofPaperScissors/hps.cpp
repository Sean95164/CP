#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N;
    cin >> N;

    vector<char> farmer(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> farmer[i];
    }

    vector<int> cowp(N+1), cowh(N+1), cows(N+1);

    for (int i = 1; i <= N; i++) {
        if (farmer[i] == 'P') {
            cowp[i]++;
        } else if (farmer[i] == 'H') {
            cowh[i]++;
        } else if (farmer[i] == 'S') {
            cows[i]++;
        }

        cowp[i] += cowp[i-1];
        cowh[i] += cowh[i-1];
        cows[i] += cows[i-1];
    }

    int wins = INT_MIN;
    for (int x = 1; x <= N; x++) {
        // P to H
        wins = max(wins, cowp[x] + (cowh[N] - cowh[x]));
        // P to S
        wins = max(wins, cowp[x] + (cows[N] - cows[x]));
        // H to P
        wins = max(wins, cowh[x] + (cowp[N] - cowp[x]));
        // H to S
        wins = max(wins, cowh[x] + (cows[N] - cows[x]));
        // S to P
        wins = max(wins, cows[x] + (cowp[N] - cowp[x]));
        // S to H
        wins = max(wins, cows[x] + (cowh[N] - cowh[x]));
    }

    cout << wins << "\n";
    return 0;
}