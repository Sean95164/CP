#include <bits/stdc++.h>

using namespace std;

struct People {
	string family;
	string name;
	
	bool operator==(People other) {
		return (family == other.family) && (name == other.name);
	}
};

int main() {
	vector<People> p;
	int n;
	cin >> n;
	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		People tmp = {a, b};
		p.push_back(tmp);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (p[i] == p[j]) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	
	cout << "No\n";
	return 0;
}