#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);


    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}