#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<string, int> age;
    map<string, string> year;
    age["Bessie"] = 0;
    year["Bessie"] = "Ox";
    vector<string> table = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    string to, from, type, tmp, animal;
    for (int i = 0; i < n; i++) {
        cin >> to >> tmp >> tmp >> type >> animal >> tmp >> tmp >> from;
        year[to] = animal;
        int f = find(table.begin(), table.end(), year[from]) - table.begin();
        int t = find(table.begin(), table.end(), year[to]) - table.begin();
        // cout << f << " " << t << "\n";
        if (type == "previous") {
            int diff = (f - t + 12) % 12;
            if (diff == 0) diff = 12;
            age[to] = age[from] - diff;
        }
        else {
            int diff = (t - f + 12) % 12;
            if (diff == 0) diff = 12;
            age[to] = age[from] + diff;
        }
    }
    // for (auto it = age.begin(); it != age.end(); it++) {
    //     cout << it->first << " " << it->second << "\n";
    // }
    cout << abs(age["Bessie"] - age["Elsie"]) << "\n";
    return 0;
}
