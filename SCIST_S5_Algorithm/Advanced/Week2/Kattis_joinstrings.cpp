#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

void print(const vector<vector<int>> &vc, const vector<string> &str, int idx) {
	cout << str[idx];
	for (auto i : vc[idx]) {
		print(vc, str, i);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<string> str(n+1);
    for (int i = 1; i <= n ; i++) {
    	cin >> str[i];
    }
    
    vector<vector<int>> vc(n+1, vector<int>());
    
    int a, b, last = 1;
    
    for (int i = 0; i < n - 1; i++) {
    	cin >> a >> b;
    	vc[a].push_back(b);
    	last = a;
    }
    
    print(vc, str, last);
    cout << "\n";
	return 0;
}