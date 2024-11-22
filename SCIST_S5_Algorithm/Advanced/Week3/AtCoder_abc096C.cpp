#include <bits/stdc++.h>

using namespace std;

const int WAYS = 4;

bool inrange(int h, int w, int x, int y) {
	return x < h && x >= 0 && y < w && y >= 0;
}

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> t;
	string in;
	for (int i = 0; i < h; i++) {
		cin >> in;
		t.push_back(in);
	}
	
	int di[] = {1, -1, 0, 0};
	int dj[] = {0, 0, 1, -1};
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (t[i][j] == '.') {
				// do nothing
			}
			else {
				bool ok = false;
				for (int c = 0; c < WAYS; c++) {
					int x = i + di[c];
					int y = j + dj[c];
					
					if (inrange(h, w, x, y)) {
						if (t[x][y] == '#') {
							ok = true;
							break;
						}
					}
				}
				
				if(!ok) {
					cout << "No\n";
					return 0;
				}
			}
		}
	}
	
	cout << "Yes\n";
	return 0;
}