#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    
    int n;
    cin >> n;

    int m;
    string name;

    vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> milk;

    for (auto s : cows) {
        milk[s] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> name >> m;
        milk[name] += m;
    }

    set<pair<int, string>> st;

    for (auto p : milk) {
        st.insert({p.second, p.first});
    }

    int smallest = (*st.begin()).first;
    int secSmallest = -1;
    for (auto p : st) {
        if (p.first == smallest) {
            continue;
        }
        if (p.first > smallest) {
            secSmallest = p.first;
            break;
        }
    }

    string ans;
    int total = 0;

    for(auto s : cows) {
        if (milk[s] == secSmallest) {
            total++;
            ans = s;
        }
    }


    if (total == 1) {
        cout << ans << endl;
    }
    else {
        cout << "Tie" << endl;
    }
    return 0;
}