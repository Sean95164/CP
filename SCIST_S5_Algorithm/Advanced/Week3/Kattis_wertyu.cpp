#include <bits/stdc++.h>

using namespace std;

string key = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int find_index(char c) {
	int len = key.size();
	for (int i = 0; i < len; i++) {
		if (key[i] == c) {
			return i;
		}
	}
	
	return -1;
}

int main() {
	string s;
	while(getline(cin, s)) {
		for (char c : s) {
			if (c == ' ') {
				cout << c;
			}
			else {
				int index = find_index(c);
				cout << key[index - 1];
			}
		}
		
		cout << "\n";
	}
	
	return 0;
}