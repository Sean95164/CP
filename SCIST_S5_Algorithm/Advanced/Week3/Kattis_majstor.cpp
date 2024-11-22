#include <bits/stdc++.h>

using namespace std;

const int LOST = 0;
const int TIE = 1;
const int WIN = 2;

const int game[3][3] = {
	{TIE, WIN, LOST}, //S SPR
	{LOST, TIE, WIN}, //P SPR
	{WIN, LOST, TIE} //R SPR
};

int to_num(const char& c) {
	if (c == 'S') {
		return 0;
	}
	else if (c == 'P') {
		return 1;
	}
	else if (c == 'R') {
		return 2;
	}
	else {
		return -1;
	}
}

int main() {
	int round;
	cin >> round;
	
	string me;
	cin >> me;
	
	int n;
	cin >> n;
	
	vector<string> others;
	string other;
	for (int i = 0; i < n; i++) {
		cin >> other;
		others.push_back(other);
	}

	int score = 0;
	vector<int> max_score(round, 0);

	for (int r = 0; r < round; r++) {
		int p1 = to_num(me[r]);
		
		// compare to others
		for (int i = 0; i < n; i++) {
			int p2 = to_num(others[i][r]);
			score += game[p1][p2];
		}
		
		// calculate max_score in this round;
		for (int c = 0; c < 3; c++) {
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				int p2 = to_num(others[i][r]);
				tmp += game[c][p2];
			}
			max_score[r] = max(max_score[r], tmp);
		}
	}
	
	cout << score << "\n";
	
	int sum = 0;
	for (int i = 0; i < round; i++) {
		sum += max_score[i];
	}
	
	cout << sum << "\n";
	return 0;
}










