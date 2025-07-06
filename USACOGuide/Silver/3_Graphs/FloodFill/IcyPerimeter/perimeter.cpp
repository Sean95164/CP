#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> gr;

int max_area;
int perimeter;

const int dr[]{-1, 1, 0, 0};
const int dc[]{0, 0, -1, 1};

void solve(int row, int col, vector<vector<bool>> &visited, int &area, int &peri) {
    if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col] || gr[row][col] == '.') {
        return;
    }

    
    visited[row][col] = true;
    area++;
    peri += 4;
    for (int i = 0; i < 4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && gr[nextRow][nextCol] == '#') {
            peri--;
        }
        solve(nextRow, nextCol, visited, area, peri);
    }
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    
    cin >> n;
    gr.resize(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string r;
    for (int i = 0; i < n; i++) {
        cin >> r;
        gr[i] = r;
    }
    max_area = INT_MIN;
    perimeter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int area = 0;
                int peri = 0;
                solve(i, j, visited, area, peri);
                if (area > max_area) {
                    max_area = area;
                    perimeter = peri;
                }
                else if (area == max_area) {
                    perimeter = min(peri, perimeter);
                }                
            }
        }
    }

    cout << max_area << " " << perimeter << "\n";
    return 0;
}