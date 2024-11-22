#include <bits/stdc++.h>

using namespace std;

bool inRange(int r, int c, int i, int j) {
	return (i >= 0 && i < r && j >= 0 && j < c);
}

int main() {
	int r, c;
	cin >> r >> c;
	
	vector<vector<char>> mp(r, vector<char>(c));
	vector<vector<bool>> visited(r, vector<bool>(c, false));
	
	char cha;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> cha;
			mp[i][j] = cha;
		}
	}
	
	visited[0][0] = true;
	
	int cur_r = 0;
	int cur_c = 0;
	
	bool ok = true;
	bool out = false;
	bool lost = false;
	
	int count = 0;
	while(mp[cur_r][cur_c] != 'T') {
		char now = mp[cur_r][cur_c];
		if (now == 'N') {
			cur_r = cur_r - 1;
		} else if (now == 'E') {
			cur_c = cur_c + 1;
		} else if (now == 'S') {
			cur_r = cur_r + 1;
		} else if (now == 'W') {
			cur_c = cur_c - 1;
		}
		
		if (!inRange(r, c, cur_r, cur_c)) {
			ok = false;
			out = true;
			break;
		}
		
		if (visited[cur_r][cur_c]) {
			ok = false;
			lost = true;
			break;
		}
		
		visited[cur_r][cur_c] = true;
		count++;
	}
	
	if (ok) {
		cout << count << "\n";
	}
	else {
		if (lost) {
			cout << "Lost\n";
		}
		if (out) {
			cout << "Out\n";
		}
	}
	return 0;
}