#include <bits/stdc++.h>

using namespace std;

int n, m, s = 1, t;

int BFS(vector<vector<int>> &graph, int **c, int **f, int *parent) {
    fill(parent + 1, parent + n + 1, 0);

    parent[s] = -1;
    queue<int> queue;
    queue.push(s);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (auto v: graph[u]) {
            if (parent[v] == 0 && f[u][v] < c[u][v]) {
                parent[v] = u;
                if(v == t) return 1;
                queue.push(v);
            }
        }
    }
    return 0;
}

int max_flow(vector<vector<int>> &graph, int **c, int **f, int *parent) {
    int res = 0;
    while (BFS(graph, c, f, parent)) {
        int flow = INT_MAX;
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, c[u][v] - f[u][v]);
        }
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            f[u][v] += flow;
            f[v][u] -= flow;
        }
        res += flow;
    }
    return res;
}

int main() {
    cin>>n>>m;
    t = n;

    vector<vector<int>> graph(n+1);

    int **c = new int * [n+1];
    int **f = new int * [n+1];
    for(int i = 1; i <= n; i++) {
        c[i] = new int[n+1];
        f[i] = new int[n+1];
        for(int j = 1; j <= n; j++) {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }
    int parent[n+1];

    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        graph[x].push_back(y);
        graph[y].push_back(x);
        c[x][y] += z;
    }

    cout<<max_flow(graph, c, f, parent);
}