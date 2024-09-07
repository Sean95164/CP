#include <bits/stdc++.h>

using namespace std;

int count(int n) {
    // Base 0,1,2,3 return 1
    if (n <= 3) {
        return 1;
    }

    return count(n - 1) + count(n - 4);
}

int main() {
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}