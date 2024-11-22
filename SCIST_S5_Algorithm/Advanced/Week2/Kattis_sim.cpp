#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	
	while(t--) {
		string s;
		getline(cin, s);
		
		list<char> d;
		auto iter = d.begin();
		
		for (char c : s) {
			if (c == '<') {
				if (iter != d.begin()) {
					iter = d.erase(--iter);
				}
			}
			else if (c == '[') {
				iter = d.begin();
			}
			else if (c == ']') {
				iter = d.end();
			}
			else {
				iter = d.insert(iter, c);
				iter++;
			}
		}
		for (auto c : d) {
			cout << c;
		}
		
		cout << "\n";
	}
	

}