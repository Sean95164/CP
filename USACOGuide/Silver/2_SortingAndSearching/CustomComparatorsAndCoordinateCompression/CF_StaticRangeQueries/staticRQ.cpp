#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

// diff uses 1-indexing
long long diff[MAXN];

long long pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> tmp;
    vector<array<int, 3>> updates;
    int l, r, v;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> v;
        updates.push_back({l, r, v});
        tmp.push_back(l);
        tmp.push_back(r);
    }

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        queries.push_back({l, r});
        tmp.push_back(l);
        tmp.push_back(r);
    }
    sort(tmp.begin(), tmp.end());

    map<int, int> toIndex;
    vector<int> distinct;
    toIndex[tmp[0]] = 0;
    distinct.push_back(tmp[0]);
    long long num = 1;
    for (size_t i = 1; i < tmp.size(); i++) {
        if (tmp[i] != tmp[i-1]) {
            toIndex[tmp[i]] = num;
            distinct.push_back(tmp[i]);
            num++;
        }
    }


    for (int i = 0; i < MAXN; i++) {
        diff[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        l = updates[i][0], r = updates[i][1], v = updates[i][2];
        diff[toIndex[l]+1] += v;
        diff[toIndex[r]+1] -= v;
    }
    for (int i = 1; i < (int) distinct.size(); i++) {
        diff[i] += diff[i-1];
    }

    pref[0] = 0;
    for (int i = 1; i < (int) distinct.size(); i++) {
        pref[i] = pref[i-1] + diff[i] * (distinct[i] - distinct[i-1]);
    }

    for (int i = 0; i < q; i++) {
        l = queries[i].first, r = queries[i].second;
        cout << pref[toIndex[r]] - pref[toIndex[l]] << "\n";
    }

    return 0;
}