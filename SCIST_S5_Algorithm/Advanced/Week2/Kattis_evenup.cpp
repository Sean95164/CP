#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	list<int> ls;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ls.push_back(x);
	}
	
	bool change = true;
	while(!ls.empty() && change) {
		change = false;

		for (auto it = ls.begin(); it != ls.end(); it++) {
			if (it == --ls.end()) {
				break;
			}
			
			auto next = it;
			next++;
			
			if ((*it + *next) % 2 == 0) {
				it = ls.erase(it);
				it = ls.erase(it);
				
				it--;
				
				change = true;
			}
		}
	}
	
	cout << ls.size() << "\n";
	return 0;
}