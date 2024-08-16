#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> piles, int n, int h, long long k) {
    int cost_hour = 0;
    for (int i = 0; i < n; i++) {
        cost_hour += ceil((double)piles[i] / k);
    }

    return h >= cost_hour;
}

int minEatingSpeed(vector<int> piles, int h) {
    int n = piles.size();
    long long total = 0;

    for (int i = 0; i < n; i++) {
        total += piles[i];
    }
    long long l = 1;
    long long r = total;
    
    long long ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if (check(piles, n, h, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, h;
    cin >> n >> h;
    
    vector<int> piles(n);
    for (int &x:piles) {
        cin >> x;
    }

    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}