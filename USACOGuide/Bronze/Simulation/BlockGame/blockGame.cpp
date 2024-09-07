#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;

   
    string w1, w2;
    vector<int> ans(26);
    for (int i = 0; i < n; i++) {
        vector<int> count1(26);
        vector<int> count2(26);
        cin >> w1 >> w2;

        int len1 = w1.size();
        int len2 = w2.size();

        for (int j = 0; j < len1; j++) {
            count1[w1[j] - 'a']++;
        }

        for (int j = 0; j < len2; j++) {
            count2[w2[j] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            ans[j] += max(count1[j], count2[j]);
        }
    }


    for (auto num : ans) {
        cout << num << endl;
    }
    
    return 0;
}