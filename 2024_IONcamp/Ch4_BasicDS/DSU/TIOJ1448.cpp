#include <bits/stdc++.h>

using namespace std;

class DSU {
    private:
    vector<int> arr;
    vector<int> sz;

    public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            arr.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int x) {
        if (x == arr[x]) return x;
        return arr[x] = find(arr[x]);
    }

    void Union(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);

        // guarantee p1 is smaller than p2
        if (sz[p1] > sz[p2]) {
            swap(p1, p2);
        }

        // union p1(smaller) to p2(bigger)
        sz[p2] += sz[p1];
        arr[p1] = arr[p2];      
    }

    bool same(int x1, int x2) {
        return find(x1) == find(x2);
    }

};

int main() {
    // Test DSU
    // DSU dsu(4);
    // dsu.Union(0, 1);
    // dsu.Union(2, 3);
    // cout << dsu.same(1,2) << endl; // false(0)

    // dsu.Union(0, 3);
    // cout << dsu.same(1,2) << endl; // true(1)

    // cout << dsu.same(2, 4) << endl; // false(0)

    int n, k;
    cin >> n >> k;
    DSU dsu(3 * n);

    int kind, x, y;
    int ans = 0;
    while(k--) {
        cin >> kind >> x >> y;
        if (x > n || y > n) {
            ans++;
            // cout << "count: " << kind << " " << x << " " << y << endl;
            continue;
        }

        if (kind == 1) {
            if (x == y) continue;
            // x is same type with y, so x doesn't eat y
            // and y doesn't eat x
            if (dsu.same(x+n, y) || dsu.same(y+n, x)) {
                ans++;
                // cout << "count: " << kind << " " << x << " " << y << endl;
                continue;
            }
            dsu.Union(x, y);
            dsu.Union(x+n, y+n);
            dsu.Union(x+2*n, y+2*n);
        }

        else if (kind == 2) {
            if (x == y) {
                ans++;
                // cout << "count: " << kind << " " << x << " " << y << endl;
                continue;
            }

            if (dsu.same(x, y) || dsu.same(x+2*n, y)) {
                ans++;
                // cout << "count: " << kind << " " << x << " " << y << endl;
                continue;
            }

            dsu.Union(x+n, y);
            dsu.Union(y+2*n, x);
            dsu.Union(y+n, x+2*n);
        }
    }

    cout << ans << "\n";
    return 0;
}