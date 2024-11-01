#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	vector<bool> visited(n+1, false);
	string result = "";
	int count = 0;
	
	while(true) {
		if (!visited[s]) {
			visited[s] = true;
			
			if (arr[s] == m) {
				result = "magic";
				break;
			}
			
			// move
			s += arr[s];
			count++;
			if (s <= 0) {
				result = "left";
				break;
			}
			if (s >= n + 1) {
				result = "right";
				break;
			}
		}
		else {
			result = "cycle";
			break;		
		}
	}
	
	cout << result << "\n";
	cout << count << "\n";
	return 0;
}