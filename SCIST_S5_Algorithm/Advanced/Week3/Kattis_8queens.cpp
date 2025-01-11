#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8;

bool valid(const vector<string> &b, const int r, const int c) {
	int tr = r + 1;
	while(tr < SIZE) {
		if (b[tr][c] == '*') {
			return false;
		}
		
		tr++;
	}
	
	int tc = c + 1;
	while(tc < SIZE) {
		if (b[r][tc] == '*') {
			return false;
		}
		
		tc++;
	}
	
	tr = r + 1;
	tc = c + 1;
	while (tr < SIZE && tc < SIZE) {
		if (b[tr][tc] == '*') {
			return false;
		}
		
		tr++;
		tc++;
	}
	
	tr = r + 1;
	tc = c - 1;
	
	while(tr < SIZE && tc >= 0) {
		if (b[tr][tc] == '*') {
			return false;
		}
		
		tr++;
		tc--;
	}
	
	return true;
}

int main() {
	vector<string> b;
	
	string s;
	for (int i = 0; i < SIZE; i++) {
		cin >> s;
		b.push_back(s);
	}

	int num = 0;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			if (b[r][c] == '*') {
				if (!valid(b, r, c)) {
					cout << "invalid\n";
					return 0;
				}
				num++;
			}
		}
	}
	
	if (num == 8) {
		cout << "valid\n";
	}
	else {
		cout << "invalid\n";
	}
	
	return 0;
}