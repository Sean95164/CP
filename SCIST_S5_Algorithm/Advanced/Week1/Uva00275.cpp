#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int a, b;
	
	while(true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		
		vector<int> visited(b, 0);
		vector<int> print;
		
		int step = 1;
		while(visited[a] == 0 && a != 0) {
			visited[a] = step;
			print.push_back(10 * a / b);
			a = a * 10 % b;
			step++;
		}
		
		
		
		int c = 1;
		cout << ".";
		
		for (int n : print) {
			if (c >= 50) {
				cout << "\n";
				c = 0;
			}
			cout << n;
			c++;
		}
		
		if (a != 0) {
			cout << "\nThe last " << step-visited[a] << " digits repeat forever.\n";
		}
		else {
			cout << "\nThis expansion terminates.\n";
		}
	}
	return 0;
}