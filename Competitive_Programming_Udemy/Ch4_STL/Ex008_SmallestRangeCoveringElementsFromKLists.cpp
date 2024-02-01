#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int row;
	int colume;
	int value;

	Node(int row, int colume, int value):row{row}, colume{colume}, value{value}{};

};

struct cmp{
	bool operator()(Node a, Node b){
		return a.value > b.value;
	}
};

vector<int> smallestRange(vector<vector<int>> nums) {
    int maxNum = INT_MIN;
    int minRange = INT_MAX;

    vector<int> ans(2);
    priority_queue<Node, vector<Node>, cmp> pq;

    int i{0};
    for(auto &k:nums){
    	sort(k.begin(), k.end());
    	pq.push(Node{i, 0, k[0]});
    	maxNum = max(maxNum, k[0]);
    	i++;
    }

    while(true){
    	// get the minimum data in priority queue
    	Node current = pq.top();
    	pq.pop();

    	int currentRange = maxNum - current.value;

    	// check if current range is bigger than the min range
    	if(minRange > currentRange){
    		ans[0] = current.value;
    		ans[1] = maxNum;
    		minRange = currentRange;
    	}

    	// check whether to stop or prepare for next round
    	if(current.colume + 1 != nums[current.row].size()){
    		maxNum = max(maxNum, nums[current.row][current.colume + 1]);
    		pq.push({current.row, current.colume + 1, nums[current.row][current.colume + 1]});
    	}
    	else{
    		break;
    	}
    }

    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int> > vc;
	int k;
	cin >> k;
	

	int n;
	int num;
	while(k--){
		vector<int> nums;
		cin >> n;
		while(n--){
			cin >> num;
			nums.push_back(num);
		}
		vc.push_back(nums);
	}
	
	vector<int> ans = smallestRange(vc);

	for(const int &num:ans){
		cout << num << " ";
	}

	cout << endl;
	return 0;
}