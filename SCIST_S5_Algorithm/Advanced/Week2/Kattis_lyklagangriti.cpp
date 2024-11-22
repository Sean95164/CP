#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	list<char> ls;
	auto pos = ls.begin();
	
	for (char c : s) {
		if (c == 'L') {
			pos--;
		}
		else if (c == 'R') {
			pos++;
		}
		else if (c == 'B') {
			pos = ls.erase(--pos);
		}
		else {
			pos = ls.insert(pos, c);
			pos++;
		}
		
		
	}
	
	for (char c : ls) {
		cout << c;
	}
	cout << "\n";
	return 0;
}