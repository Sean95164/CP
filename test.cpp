#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
const long long INF = 1e12;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> house(n);

    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    long long left = 0, right = INF;
    while(right - left > 1) {
        long long x = (left + right) / 2;
        int cnt = 1;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (house[i] - house[prev] >= x) {
                cnt++;
                prev = i;
            }
        }

        if (cnt >= m) left = x;
        else right = x;
    }

    cout << left << endl;
    return 0;
}