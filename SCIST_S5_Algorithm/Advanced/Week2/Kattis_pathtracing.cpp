#include <bits/stdc++.h>

using namespace std;

int main() {
	deque<string> d;
	d.push_back("*");
	
	int sx = 0, sy = 0;
	int cx = 0, cy = 0;
	
	string move;
	while(cin >> move) {
		if (move == "down") {
			cy++;
			if (cy >= d.size()) {
				string tmp(d[0].size(), ' ');
				d.push_back(tmp);
			}
		}
		else if (move == "up") {
			cy--;
			if (cy < 0) {
				cy++;
				sy++;
				string tmp(d[0].size(), ' ');
				d.push_front(tmp);
			}
		}
		else if (move == "right") {
			cx++;
			if (cx >= d[0].size()) {
				for (auto &s : d) {
					s.push_back(' ');
				}
			}
		}
		else if (move == "left") {
			cx--;
			if (cx < 0) {
				cx++;
				sx++;
				for (auto &s : d) {
					s.insert(s.begin(), ' ');
				}
			}
		}
		
		d[cy][cx] = '*';
	}	
	
	d[cy][cx] = 'E';
	d[sy][sx] = 'S';
	
	for (auto &s : d) {
		s.insert(s.begin(), '#');
		s.push_back('#');
	}
	
	for (int i = 0; i < d[0].size(); i++) {
		cout << "#";
	}
	cout << "\n";
	
	for (auto s : d) {
		cout << s << "\n";
	}
	
	for (int i = 0; i < d[0].size(); i++) {
		cout << "#";
	}
	cout << "\n";
	return 0;
}