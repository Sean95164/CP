#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> nums; 

void func(ll &nume, ll &deno, int index) {
	if (index == nums.size() - 1) {
		nume = nums[index];
		deno = 1;
		return;
	}
	
	func(nume, deno, index + 1);
	
	swap(nume, deno);
	nume += deno * nums[index]; 
}

int main() {
	int n;
	cin >> n;
	
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}
	
	ll nume = 1, deno = 1;
	
	func(nume, deno, 0);
	
	ll tmp = gcd(nume, deno);
	if (tmp != 1) {
		nume /= tmp;
		deno /= tmp;
	}
	
	cout << nume << "/" << deno << "\n";
	return 0;
}