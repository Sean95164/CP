#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int i = 0, j = 0;
    int total = 0; 
    int ans = 0;
    while (i < n) {
        if (j < i) {
            j = i;
        }
        while(j < n && total + cost[j] <= t) {
            total += cost[j];
            j++;
        }
        // cout << i << " " << j << " " << total <<  "\n";
        ans = max(ans, j - i);
        if (i != j) {
            total -= cost[i];
        }
        
        i++;
    }

    cout << ans << "\n";
    return 0;
}