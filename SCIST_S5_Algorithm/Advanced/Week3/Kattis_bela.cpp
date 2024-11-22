#include <bits/stdc++.h>

using namespace std;

const int NUMS = 8;

int to_num(char c) {
	char t[] = {
		'A',
		'K',
		'Q',
		'J',
		'T',
		'9',
		'8',
		'7'
	};
	
	for (int i = 0; i < NUMS; i++) {
		if (t[i] == c) {
			return i;
		}
	}
	
	return -1;
}

int score[NUMS][2] = {
	{11, 11},
	{4, 4},
	{3, 3},
	{2, 20},
	{10, 10},
	{0, 14},
	{0, 0},
	{0, 0}
};

int main() {
	int n;
	char b;
	
	cin >> n >> b;
	
	int total = 0;
	string card;
	for (int i = 0; i < 4 * n; i++) {
		cin >> card;
		bool domi = (b == card[1]);
		int num = to_num(card[0]);
		// cout << num << "\n";
		total += score[num][domi];
	}
	
	cout << total << "\n";
	return 0;
}