#include <bits/stdc++.h>

using namespace std;

void dfs(map<string, vector<string>> graph, set<pair<string, string>> &visited, string curr, vector<string> &ans) {
    ans.push_back(curr);

    for (string nbr : graph[curr]) {
        if (!visited.count({curr, nbr})) {
            visited.insert({curr, nbr});
            dfs(graph, visited, nbr, ans);
        }
    }
}

vector<string> findItinerary(vector<vector<string>> tickets) {
    map<string, vector<string>> graph;
    for (auto p : tickets) {
        string from = p[0];
        string to = p[1];

        graph[from].push_back(to);
    }

    // sort all vectors in map
    for (auto& v : graph) {
        sort(v.second.begin(), v.second.end());
    }

    set<pair<string, string>> visited;
    vector<string> ans;
    dfs(graph, visited, "JFK", ans);
    return ans;
}

int main() {
    vector<vector<string>> tickets = {
        {"MUC","LHR"},
        {"JFK","MUC"},
        {"SFO","SJC"},
        {"LHR","SFO"}
    };

    vector<string> ans = findItinerary(tickets);
    for (string s : ans) {
        cout << s << ", ";
    }

    cout << "\n";
    return 0;
}