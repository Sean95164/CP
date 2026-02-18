#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;
    vector<long long> milks(n);
    for (int i = 0; i < n; i++) {
        cin >> milks[i];
    }    
    vector<pair<long long, long long>> store(m);
    for (int i = 0; i < m; i++) {
        cin >> store[i].first >> store[i].second;
    }
    vector<long long> rent(r);
    for (int i = 0; i < r; i++) {
        cin >> rent[i];
    }

    sort(milks.rbegin(), milks.rend());
    sort(store.begin(), store.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    });
    sort(rent.rbegin(), rent.rend());

    long long total = 0;
    int rent_id = 0;
    int store_id = 0;
    int cow = 0;
    while(cow < n) {
        // cout << cow << ": "; 
        long long milk_profit = 0;
        long long rent_profit = (rent_id < r ? rent[rent_id] : 0); 
        long long milk = milks[cow];

        int tmp_store_id = store_id;
        vector<int> record;
        while(tmp_store_id < m && milk > 0) {
            int amount = min(store[tmp_store_id].first, milk);
            milk_profit += amount * store[tmp_store_id].second;
            if (amount == store[tmp_store_id].first) {
                tmp_store_id++;
            }
            record.push_back(amount);
            milk -= amount;
        }
        if (rent_profit > milk_profit) {
            total += rent_profit;
            rent_id++;
            // cout << rent_profit << "\n";
            n--;
        }
        else {
            total += milk_profit;
            for (int j = 0; j < (int) record.size(); j++) {
                store[store_id].first -= record[j];
                store_id++;
            }
            store_id = tmp_store_id;
            // cout << milk_profit << "\n";
            cow++;
        }
    }

    cout << total << "\n";
    return 0;
}