#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 200;
const int INF = INT_MAX;

int n, m, s = 1, t; // количество вершин, количество ребер, источник, сток
int c[MAXN][MAXN], f[MAXN][MAXN], p[MAXN]; // пропускные способности, потоки, массив предков
vector<int> g[MAXN]; // граф

int bfs() {
    queue<int> q;
    q.push(s);
    memset(p, -1, sizeof(p));
    p[s] = -2;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (p[u] == -1 && f[v][u] < c[v][u]) {
                p[u] = v;
                if (u == t) return 1;
                q.push(u);
            }
        }
    }
    return 0;
}

int max_flow() {
    int flow = 0;
    while (bfs()) {
        int cur_flow = INF;
        for (int u = t; u != s; u = p[u]) {
            int v = p[u];
            cur_flow = min(cur_flow, c[v][u] - f[v][u]);
        }
        for (int u = t; u != s; u = p[u]) {
            int v = p[u];
            f[v][u] += cur_flow;
            f[u][v] -= cur_flow;
        }
        flow += cur_flow;
    }
    return flow;
}

int main() {
    cin >> n >> m;
    t = n;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u][v] += w;
    }
    cout << max_flow() << endl;
    return 0;
}