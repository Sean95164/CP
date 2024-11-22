#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int len = s.size();
	
	char table[256];
	table['0'] = '0';
	table['1'] = '1';
	table['8'] = '8';
	table['6'] = '9';
	table['9'] = '6';
	
	for (int i = len - 1; i >= 0; i--) {
		cout << table[s[i]];
	}
	
	cout << "\n";
	return 0;
}