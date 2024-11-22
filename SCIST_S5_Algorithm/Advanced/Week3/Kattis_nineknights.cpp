#include <bits/stdc++.h>

using namespace std;

const int H = 5;
const int W = 5;
const int WAYS = 8;

bool inrange(const int h, const int w, const int x, const int y) {
	return x < h && x >= 0 && y < w && y >= 0;	
}

int main() {
	vector<string> t;
	
	string row;
	for (int i = 0; i < H; i++) {
		cin >> row;
		t.push_back(row);
	}
	
	int di[] = {1, 1, 2, 2, -1, -1, -2, -2};
	int dj[] = {2, -2, 1, -1, 2, -2, 1, -1};
	
	int num = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (t[i][j] == '.') {
				// do nothing
			}
			else {
				for (int c = 0; c < WAYS; c++) {
					int x = i + di[c];
					int y = j + dj[c];
					if (inrange(H, W, x, y)) {
						// check valid
						if (t[x][y] == 'k') {
							cout << "invalid\n";
							return 0;
						}
					}
				}
				num++;
			}
		}
	}
	if (num == 9) {
		cout << "valid\n";
	}
	else {
		cout << "invalid\n";
	}
	return 0;
}