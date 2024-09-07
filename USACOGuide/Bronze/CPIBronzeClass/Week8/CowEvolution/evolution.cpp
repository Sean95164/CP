#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    
    int n;
    cin >> n;
    
    set<string> allFeatures;
    vector<vector<string>> cows(n);

    int k;
    string feature;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> feature;
            allFeatures.insert(feature);
            cows[i].push_back(feature);
        }
    }
    string ans = "yes";
    bool A = false, B = false, AB = false;
    // check all 
    for (auto f1 = allFeatures.begin(); f1 != allFeatures.end(); f1++) {
        for (auto f2 = next(f1); f2 != allFeatures.end(); f2++) {
            A = false, B = false, AB = false;
            for (auto cow : cows) {
                if (find(cow.begin(), cow.end(), *f1) != cow.end() &&
                    find(cow.begin(), cow.end(), *f2) != cow.end()) {
                        AB = true;
                }
                else if (find(cow.begin(), cow.end(), *f1) != cow.end()) {
                    A = true;
                }
                else if (find(cow.begin(), cow.end(), *f2) != cow.end()) {
                    B = true;
                }
            }

            if (A && B && AB) {
                ans = "no";
                break;
            }
        }
        if (ans == "no") {
            break;
        }
    }


    cout << ans << "\n";
    return 0;
}