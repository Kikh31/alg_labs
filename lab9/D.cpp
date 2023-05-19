#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<int> topArr;

void dfs(vector<vector<int> > &graph, int u, bool *visited) {
    visited[u] = true;
    for (auto v: graph[u]) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
    topArr.push_back(u);
}

void topologicalSort(vector<vector<int> > &graph, bool *visited) {
    fill(visited + 1, visited + n + 1, false);
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
    reverse(topArr.begin(), topArr.end());
}

int main() {
    cin >> n >> m;

    vector<vector<int> > graph(n + 1);
    bool visited[n+1];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    topologicalSort(graph, visited);

    vector< pair<int, int> > ans;
    for(int i = 1; i <= n; i++) {
        ans.push_back(make_pair(topArr[i-1], i));
    }
    sort(ans.begin(), ans.end());

    for(auto x : ans) cout<<x.second<<" ";
}