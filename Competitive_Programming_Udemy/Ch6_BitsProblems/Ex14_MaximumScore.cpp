#include <bits/stdc++.h>

using namespace std;

void flipMatrixRow(vector<vector<int> > &grid, int m, int n){
	for(int i=0;i<n;i++){
		if(grid[m][i] == 1){
			grid[m][i] = 0;
		}
		else
			grid[m][i] = 1;
	}
}

void flipMatrixColumn(vector<vector<int> > &grid, int m, int n){
	for(int i=0;i<m;i++){
		if(grid[i][n] == 1){
			grid[i][n] = 0;
		}
		else
			grid[i][n] = 1;
	}
}

bool zerosGreaterThanOnes(const vector<vector<int> > &grid, int n){
	int m = grid.size();
	int zeros = 0;

	for(int i=0;i<m;i++){
		if(grid[i][n] == 0)
			zeros++;
	}

	return (2*zeros - m > 0);

}

int sumMatrix(const vector<vector<int>> &grid, int m, int n){
	int result = 0;
	

	for(int i=0;i<m;i++){
		int num = 0;
		for(int j=0;j<n;j++){
			num += (1 << (n-1-j))*grid[i][j];
		}
		result += num;
	}

	return result;
}

void display(const vector<vector<int> > &grid){
	for(const auto row:grid){
		for(const auto &num:row){
			cerr << num << " ";
		}
		cerr << endl;
	}
}

int matrixScore(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();

    // check each matrix[m][0] whether equal to 0
    for(int i=0;i<m;i++){
    	if(grid[i][0] == 0){
    		flipMatrixRow(grid, i, n);
    	}
    }

    for(int j=0;j<n;j++){
    	if(zerosGreaterThanOnes(grid, j)){
    		flipMatrixColumn(grid, m, j);
    	}
    }
	// display(grid);
    int sum = sumMatrix(grid, m, n);
    return sum;
    // return -1;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m,n;
	cin >> m >> n;
	vector<vector<int> > matrix;
	
	int bit;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			cin >> bit;
			temp.push_back(bit);
		}
		matrix.push_back(temp);
	}

	cout << matrixScore(matrix) << endl;
	
	return 0;
}