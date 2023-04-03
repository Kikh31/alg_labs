#include <bits/stdc++.h>

using namespace std;

int n, m;

int BFS(vector<vector<int>> &graph, int source, int destination) {
    int d[n + 1];
    int parent[n + 1];
    fill(d + 1, d + n + 1, INT_MAX);
    fill(parent + 1, parent + n + 1, 0);

    d[source] = 0;
    queue<int> queue;
    queue.push(source);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int i = 1; i <= n; i++) {
            for (auto v: graph[u]) {
                if (d[v] == INT_MAX) {
                    d[v] = d[u] + 1;
                    parent[v] = u;
                    queue.push(v);
                }
            }
        }
    }
    return d[destination];
}

int main() {
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    int res = BFS(graph, s, f);
    if (res == INT_MAX) {
        cout << -1;
    } else {
        cout << res;
    }
}