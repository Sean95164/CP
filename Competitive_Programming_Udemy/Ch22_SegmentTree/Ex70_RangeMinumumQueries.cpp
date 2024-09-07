#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
        vector<int> tr;
        int size;
        void build(int start, int end, int cur, vector<int> &arr) {
            if (start == end) {
                tr[cur] = arr[start];
                return;
            }

            int mid = (start + end) / 2;
            build(start, mid, 2 * cur + 1, arr);
            build(mid + 1, end, 2 * cur + 2, arr);

            tr[cur] = min(tr[2 * cur + 1], tr[2 * cur + 2]);
        }

    public:
        SegmentTree(int n, vector<int> &arr) {
            this->size = n;
            tr.resize(4 * n, 0);
            build(0, size - 1, 0, arr);
        }

        int query(int start, int end, int cur, int l, int r) {
            // non-overlapping
            if (r < start || l > end) {
                return INT_MAX;
            }

            // complete-overlapping
            if (l <= start && r >= end) {
                return tr[cur];
            }

            // partial overlapping
            int mid = (start + end) / 2;
            int q1 = query(start, mid, 2 * cur + 1, l ,r);
            int q2 = query(mid + 1, end, 2 * cur + 2, l, r);

            return min(q1, q2);
        }

        int query(int l, int r) {
            return query(0, size - 1, 0, l, r);
        }

        void update(int start, int end, int cur, int index, int value) {
            if (start == end) {
                tr[cur] = value;
                return;
            }

            int mid = (start + end) / 2;
            if (index <= mid) {
                update(start, mid, 2 * cur + 1, index, value);
            }
            else {
                update(mid + 1, end, 2 * cur + 2, index, value);
            }

            tr[cur] = min(tr[2 * cur + 1], tr[2 * cur + 2]);
        }

        void update(int index, int value) {
            update(0, size - 1, 0, index, value);
        }
};

vector<int> solve(int n, vector<int>arr, vector<vector<int>> queries) {
    SegmentTree SgTree(n, arr);

    vector<int> ans;

    int t, a, b;
    for (auto p : queries) {
        t = p[0];
        a = p[1];
        b = p[2];
        a--;

        if (t == 1) {
            SgTree.update(a, b);
        }
        else if (t == 2) {
            b--;
            ans.push_back(SgTree.query(a, b));
        }
    }

    return ans;
}

int main() {
    int n = 8;
    vector<int> arr = {3, 2, 4, 5, 1, 1, 5, 3};
    vector<vector<int>> queries = {
        {2, 1, 4},
        {2, 5, 6},
        {1, 2, 3},
        {2, 1, 4}
    };

    vector<int> ans = solve(n, arr, queries);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}