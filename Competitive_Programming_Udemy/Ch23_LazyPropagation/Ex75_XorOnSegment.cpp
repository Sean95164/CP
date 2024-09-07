#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
        vector<long long> tr;
        int size;

        void build(int start, int end, int cur, vector<int> &a) {
            if (start == end) {
                tr[cur] = a[start];
                return;
            }
            
            int mid = (start + end) / 2;
            build(start, mid, 2 * cur + 1, a);
            build(mid + 1, end, 2 * cur + 2, a);

            tr[cur] = tr[2 * cur + 1] + tr[2 * cur + 2];
            return;
        }

    public:
        SegmentTree(int n, vector<int> &a) {
            size = n;
            tr.resize(4 * n, 0);
            build(0, size - 1, 0, a);
        }

        long long query(int start, int end, int cur, int l, int r) {
            // non-overlapping
            if (l > end || r < start) {
                return 0;
            }

            // complete-overlapping
            if (l <= start && r >= end) {
                return tr[cur];
            }

            // partial overlapping
            int mid = (start + end) / 2;
            long long q1 = query(start, mid, 2 * cur + 1, l, r);
            long long q2 = query(mid+1, end, 2 * cur + 2, l, r);

            return q1 + q2;
        }

        long long query(int l, int r) {
            return query(0, size - 1, 0, l, r);
        }

        void update(int start, int end, int cur, int index, int value) {
            if (start == end) {
                tr[cur] ^= value;
                return;
            }

            int mid = (start + end) / 2;
            if (index <= mid) {
                update(start, mid, 2 * cur + 1, index, value);
            }
            else {
                update(mid+1, end, 2 * cur + 2, index, value);
            }

            tr[cur] = tr[cur * 2 + 1] + tr[cur * 2 + 2];
            return;
        }

        void update(int index, int value) {
            update(0, size - 1, 0, index, value);
        }
};

vector<long long> solve(int n,int q, vector<int> a, vector<vector<int>> query) {
    SegmentTree SegTree(n, a);

    vector<long long> ans;
    int t, x, y, value;
    for (int i = 0; i < q; i++) {
        t = query[i][0];
        x = query[i][1];
        y = query[i][2];
        x--;
        y--;

        if (t == 1) {
            ans.push_back(SegTree.query(x, y));
        }
        else if (t == 2) {
            value = query[i][3];
            for (int j = x; j <= y; j++) {
                SegTree.update(j, value);
            }
            
        }
    }

    return ans;
}

int main() {
    int n = 5;
    int q = 8;
    vector<int> a = {4, 10, 3, 13, 7};
    vector<vector<int>> query = {
        {1, 2, 4},
        {2, 1, 3, 3},
        {1, 2, 4},
        {1, 3, 3},
        {2, 2, 5, 5},
        {1, 1, 5},
        {2, 1, 2, 10},
        {1, 2, 3}
    };

    vector<long long> ans = solve(n, q, a, query);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}