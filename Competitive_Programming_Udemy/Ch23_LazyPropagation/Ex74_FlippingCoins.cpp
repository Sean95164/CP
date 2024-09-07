#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
        vector<int> tr, lazy;
        int size;

    public:
        SegmentTree(int n) {
            size = n;
            tr.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
        }

        int query(int start, int end, int cur, int l, int r) {
            //non-overlapping
            if (l > end || r < start) {
                return 0;
            }

            // push lazy propagation
            if (lazy[cur] != 0) {
                if (lazy[cur]&1) {
                    tr[cur] = (end - start + 1) - tr[cur];
                }

                if (start != end) {
                    lazy[2 * cur + 1] += lazy[cur];
                    lazy[2 * cur + 2] += lazy[cur];
                }
                lazy[cur] = 0;
            }
            
            // complete-overlapping
            if (r >= end && l <= start) {
                return tr[cur];
            }

            int mid = (start + end) / 2;
            int q1 = query(start, mid, 2 * cur + 1, l ,r);
            int q2 = query(mid + 1, end, 2 * cur + 2, l, r);
        
            return q1 + q2;
        }

        int query(int l, int r) {
            return query(0, size - 1, 0, l, r);
        }

        void update(int start, int end, int cur, int l, int r) {
            //non-overlapping
            if (l > end || r < start) {
                return;
            }

            // push lazy propagation
            if (lazy[cur] != 0) {
                if (lazy[cur]&1) {
                    tr[cur] = (end - start + 1) - tr[cur];
                }
                
                if (start != end) {
                    lazy[2 * cur + 1] += lazy[cur];
                    lazy[2 * cur + 2] += lazy[cur];
                }
                lazy[cur] = 0;
            }

            // complete-overlapping
            if (r >= end && l <= start) {
                tr[cur] = (end - start + 1) - tr[cur];
                if (start != end) {
                    lazy[2 * cur + 1] += 1;
                    lazy[2 * cur + 2] += 1;
                }
                return;
            }

            int mid = (start + end) / 2;
            update(start, mid, 2 * cur + 1, l ,r);
            update(mid + 1, end, 2 * cur + 2, l, r);
        
            tr[cur] = tr[2 * cur + 1] + tr[2 * cur + 2];
            return;
        }

        void update(int l, int r) {
            update(0, size - 1, 0, l, r);
        }
};

vector<int> solve(int n,int q, vector<vector<int>> query) {
    SegmentTree SgTree(n);

    vector<int> ans;
    int t, a, b;
    for (int i = 0; i < q; i++) {
        t = query[i][0];
        a = query[i][1];
        b = query[i][2];

        if (t == 0) {
            SgTree.update(a, b);
        }
        else if (t == 1) {
            ans.push_back(SgTree.query(a, b));
        }
    }
    return ans;
}

int main() {
    int n = 4;
    int q = 7;
    vector<vector<int>> query = {
        {1, 0, 3},
        {0, 1, 2},
        {1, 0, 1},
        {1, 0, 0},
        {0, 0, 3},
        {1, 0, 3},
        {1, 3, 3}
    };

    vector<int> ans = solve(n, q, query);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}