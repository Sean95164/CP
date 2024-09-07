#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    // using Bellman-ford algorithm
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < k+1; i++) {
        // alway update the next node from known dist node step by step
        vector<int> tmp(dist);

        for (auto p : flights) {
            int from = p[0];
            int to = p[1];
            int price = p[2];

            if (dist[from] != INT_MAX && tmp[to] > price + dist[from]) {
                tmp[to] = price + dist[from];
            }
        }

        dist = tmp;
    }

    return (dist[dst] == INT_MAX ? -1 : dist[dst]);
}


int main() {
    int n = 3;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };

    int src = 0;
    int dst = 2;
    int k = 0;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}