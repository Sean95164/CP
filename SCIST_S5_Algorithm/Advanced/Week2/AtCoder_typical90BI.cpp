#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	
	deque<int> decks;
	vector<int> print;
	
	int t, x;
	while(q--) {
		cin >> t >> x;
		if (t == 1) {
			decks.push_front(x);
		}
		else if (t == 2) {
			decks.push_back(x);
		}
		else {
			print.push_back(decks[x-1]);
		}
	}
	
	for (int num : print) {
		cout << num << "\n";
	}
	return 0;
}