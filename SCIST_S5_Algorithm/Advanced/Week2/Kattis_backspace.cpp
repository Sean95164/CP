#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	
	cin >> s;
	
	vector<char> vc;
	for (char c : s) {
		if (c == '<') {
			vc.pop_back();
		}
		else {
			vc.push_back(c);
		}
	}
	
	for (char c : vc) {
		cout << c;
	}
	
	cout << "\n";
	return 0;
}