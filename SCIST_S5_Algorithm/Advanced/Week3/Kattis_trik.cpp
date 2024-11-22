#include <bits/stdc++.h>

using namespace std;

const int N_CUPS = 3;


int main() {
	string cmd;
	
	cin >> cmd;
	bool cups[N_CUPS] = {true};
	vector<vector<int>> actions = {
		{0, 1},
		{1, 2},
		{0, 2}
	};
	
	int len = cmd.size();
	for (int i = 0; i < len; i++) {
		int t = cmd[i] - 'A';
		swap(cups[actions[t][0]], cups[actions[t][1]]);
	}
	
	for (int i = 0; i < N_CUPS; i++) {
		if (cups[i]) {
			cout << i+1 << "\n";
			break;
		}
	}
	return 0;
}