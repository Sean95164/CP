#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    map<pair<string, string>, long long> nums;
    int n;
    cin >> n;
    string name, code1, code2;
    for (int i = 0; i < n; i++) {
        cin >> name >> code2;
        code1 = name.substr(0, 2);
        nums[{code1, code2}]++;
    }

    long long total = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        auto key = it->first;
        if (key.first == key.second) continue;
        total += nums[key] * nums[{key.second, key.first}];
    }

    cout << total / 2 << "\n";
    return 0;
}