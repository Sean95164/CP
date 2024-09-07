#include<bits/stdc++.h>
using namespace std;

class Fenwick {
        vector<int> fr;

    public:
        Fenwick(int n) {
            fr.resize(n+1, 0);
        }

        void add(int index, int value) {
            index++;
            while(index < fr.size()) {
                fr[index] += value;
                index += (index & (-index));
            }
        }

        int query(int index) {
            index++;
            int ans = 0;
            while(index) {
                ans += fr[index];
                index -= (index & (-index));
            }

            return ans;
        }

        int query(int l, int r) { // 1-based
            return query(r) - query(l - 1);
        }
};

vector<int> solve(int n, vector<int> nums, vector<vector<int>> queries) {
    vector<int> ans;

    Fenwick tree(n);
    for (int i = 0; i < n; i++) {
        tree.add(i, nums[i]);
    }

    int t, a, b, u, k;
    for (auto p : queries) {
        t = p[0];
        if (t == 1) {
            a = p[1];
            b = p[2];
            a--;
            b--;

            u = p[3];
            for (int i = a; i <= b; i++) {
                tree.add(i, u);
            }
        }
        else if (t == 2) {
            k = p[1];
            k--;

            ans.push_back(tree.query(k, k));
        }
    }

    return ans;
}

int main() {
    int n = 8;
    vector<int> nums = {3, 2, 4, 5, 1, 1, 5, 3};

    vector<vector<int>> queries = {
        {2, 4},
        {1, 2, 5, 1},
        {2, 4}
    };

    vector<int> ans = solve(n, nums, queries);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}