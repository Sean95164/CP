#include <bits/stdc++.h>

using namespace std;

bool valid(const vector<int> &cities, const vector<int> &towers, long long r) {
    int i = 0, j = 0;
    while(i < (int) cities.size() && j < (int) towers.size()) {
        while (i < (int) cities.size() && abs(cities[i]-towers[j]) <= r) {
            i++;
        }

        j++;
    }
    return i == (int) cities.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cities(n), towers(m);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    long long left = 0, right = 1e10;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (valid(cities, towers, mid)) {
            right = mid;
        }
        else {
            left = mid+1;
        }
    }

    cout << left << "\n";
    return 0;
}