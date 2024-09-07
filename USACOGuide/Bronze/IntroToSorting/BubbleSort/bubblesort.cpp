#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                total++;
                swap(a[j], a[j + 1]);
            }
        }
    }

    cout << "Array is sorted in " << total << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[n-1] << "\n";
    return 0;
}