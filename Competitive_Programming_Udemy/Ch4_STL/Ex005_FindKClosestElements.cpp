#include <bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
	vector<int> ans;
	int mid = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	
	int left = mid - 1;
	int right = mid;
	while(ans.size() != k){
		if(left < 0){
			ans.push_back(arr[right]);
			right++;
			continue;
		}

		if(right >= arr.size()){
			ans.push_back(arr[left]);
			left--;
			continue;
		}

		if(x - arr[left] <= arr[right] - x){
			ans.push_back(arr[left]);
			left--;
		}
		else{
			ans.push_back(arr[right]);
			right++;
		}
	}

	sort(ans.begin(), ans.end());
	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vc;
	int t;
	cin >> t;

	int num;
	while(t--){
		cin >> num;
		vc.push_back(num);
	}	

	int k, n;
	cin >> k >> n;
	vector<int> ans = findClosestElements(vc, k, n);
	for(const int &num:ans){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}