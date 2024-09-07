#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
        vector<int> tree;
        int size;

        void build(int start, int end, int cur, vector<int> &v) {
            if (start == end) {
                tree[cur] = v[start];
                return;
            }

            int mid = (start + end) / 2;
            build(start, mid, 2 * cur + 1, v);
            build(mid + 1, end, 2 * cur + 2, v);
            
            tree[cur] = tree[2 * cur + 1] ^ tree[2 * cur + 2];
        }

    public:
        SegmentTree(int n, vector<int> &v) {
            this->size = n;
            tree.resize(4 * size, 0);
            build(0, size - 1, 0, v);
        }

        int query(int start, int end, int cur, int l, int r) {
            // non-overlapping
            if (r < start || l > end) {
                return 0;
            }

            // overlapping
            if (l <= start && r >= end) {
                return tree[cur];
            }

            int mid = (start + end) / 2;
            int q1 = query(start, mid, 2 * cur + 1, l, r);
            int q2 = query(mid + 1, end, 2 * cur + 2, l, r);

            return q1 ^ q2;
        }

        int query(int l, int r) {
            return query(0, size - 1, 0, l, r);
        }
};

vector<int> solve(int n, vector<int> a, vector<vector<int>> queries) {
    SegmentTree tree(a.size(), a);
    
    vector<int> ans;

    int l, r;
    for (auto each : queries) {
        l = each[0];
        r = each[1];
        l--;
        r--;
        
        ans.push_back(tree.query(l, r));
    }

    return ans;
}

int main() {
    int n = 5;
    vector<int> a = {3, 2, 4, 5, 1, 1, 5, 3};
    vector<vector<int>> queries = {
        {2, 4},
        {5, 6},
        {1, 8},
        {3, 3}
    };
    vector<int> ans = solve(n, a, queries);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}