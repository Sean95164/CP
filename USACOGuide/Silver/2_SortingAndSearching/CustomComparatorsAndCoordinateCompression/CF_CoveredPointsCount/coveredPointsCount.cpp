#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;
long long cnt[MAXN];
long long diff[MAXN];

vector<long long> distinct;
int toIndex(long long x) {
    return lower_bound(distinct.begin(), distinct.end(), x) - distinct.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<pair<long long, long long>> segs(n);
    vector<long long> tmp;
    for (int i = 0; i < n; i++) {
        cin >> segs[i].first >> segs[i].second;
        tmp.push_back(segs[i].first);
        tmp.push_back(segs[i].second+1);
    }
    sort(tmp.begin(), tmp.end());

    distinct.push_back(tmp[0]);
    for (int i = 1; i < (int) tmp.size(); i++) {
        if (tmp[i] != tmp[i-1]) {
            distinct.push_back(tmp[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        long long l = segs[i].first, r = segs[i].second;
        diff[toIndex(l)]++;
        diff[toIndex(r+1)]--;
    }
    for (int i = 1; i < (int) distinct.size(); i++) {
        diff[i] += diff[i-1];
    }

    // for (int i = 0; i < (int) distinct.size(); i++) {
    //     cout << diff[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < (int) distinct.size(); i++) {
    //     cout << distinct[i] << " ";
    // }

    int i;
    for (i = 1; i < (int) distinct.size(); i++) {
        cnt[diff[i-1]] += distinct[i] - distinct[i-1];
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << cnt[i];
        }
        else {
            cout << " " << cnt[i];
        }
    }
    cout << "\n";
    return 0;
}