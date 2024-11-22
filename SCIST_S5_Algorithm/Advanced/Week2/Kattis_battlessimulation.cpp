#include <bits/stdc++.h>

using namespace std;

bool combo(const string &monster, int index) {
	bool R = false;
	bool B = false;
	bool L = false;
	
	for (int i = index; i < index + 3; i++) {
		if (monster[i] == 'R') {
			R = true;
		}
		else if (monster[i] == 'B') {
			B = true;
		}
		else if (monster[i] == 'L') {
			L = true;
		}
	}
	
	return R && B && L;
}

int main() {
	string monster;
	
	cin >> monster;
	
	vector<char> ans;
	
	int len = monster.size();
	for (int i = 0; i < len; i++) {
		if (i < len - 2) {
			if (combo(monster, i)) {
				ans.push_back('C');
				i += 2;
				continue;
			}
		}
		
		if (monster[i] == 'R') {
			ans.push_back('S');
		}
		else if (monster[i] == 'B') {
			ans.push_back('K');
		}
		else if (monster[i] == 'L') {
			ans.push_back('H');
		}
	}
	
	for (char c : ans) {
		cout << c;
	}
	
	cout << "\n";
	return 0;
}