#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int q;
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		
		vector<int> vc(k, -1);
		int f0 = 1;
		int f1 = 1;
		int i = 2;
		while(true) {
			int f2 = f0 + f1;
			f2 = f2 % k;
			if (vc[f2] != -1) {
				cout << vc[f2] << "\n";
				break;
			}
			
			vc[f2] = i;
			
			f0 = f1;
			f1 = f2;
			i++;
		}
	}
	
	return 0;
}