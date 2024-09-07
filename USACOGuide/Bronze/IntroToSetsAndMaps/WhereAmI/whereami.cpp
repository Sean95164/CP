#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    
    int k = 1;
    while(true) {
        bool found = true;
        set<string> st;
        for (int i = 0; i < n - k + 1; i++) {
            string sub = s.substr(i, k);
            if (st.count(sub)) {
                found = false;
                break;
            }
            st.insert(sub);       
        }

        if (found) {
            break;
        }
        
        k++;
    }


    cout << k << endl;

    return 0;
}