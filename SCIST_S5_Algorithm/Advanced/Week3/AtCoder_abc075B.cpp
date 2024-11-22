#include <bits/stdc++.h>

using namespace std;

const int DIRS = 8;

bool inrange(int h, int w, int x, int y) {
	return x < h && x >= 0 && y < w && y >= 0;
}

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> t;
	string s;
	for (int i = 0; i < h; i++) {
		cin >> s;
		t.push_back(s);
	}
	
	int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dj[] = {0, -1, 1, -1, 1, 0, -1, 1};

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (t[i][j] == '#') {
				// do nothing
			}
			else {
				int c = 0;
				for (int d = 0; d < DIRS; d++) {
					int x = i + di[d];
					int y = j + dj[d];
					if (inrange(h, w, x, y) && t[x][y] == '#') {
						c++;
					}
				}
				
				t[i][j] = '0' + c;
			}

			cout << t[i][j];
		}
		cout << "\n";
	}
	return 0;
}