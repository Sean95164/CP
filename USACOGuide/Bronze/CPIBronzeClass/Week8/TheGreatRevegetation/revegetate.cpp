#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    map<int, vector<int>> gr;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<int> put(n+1, 0);

    // do choice for each pasture
    for (int i = 1; i <= n; i++) {
        // try each different seed from 1 to 4 
        for (int j = 1; j <= 4; j++) {
            // check valid
            bool valid = true;
            for (auto nbr : gr[i]) {
                if (put[nbr] == j) {
                    valid =  false;
                    break;
                }
            }

            if (valid) {
                put[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << put[i];
    }

    cout << "\n";
    return 0;
}