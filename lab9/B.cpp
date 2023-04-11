#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, q;

int BFS(vector<vector<int> > &graph, int source, int destination) {
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
        for (auto v: graph[u]) {
            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                parent[v] = u;
                queue.push(v);
            }
        }
    }
    return d[destination];
}

void eraseV(vector< vector<int> > &graph, int s, int f) {
    int ptr = 0;
    while (graph[s][ptr] != f) ptr++;
    graph[s].erase(graph[s].begin() + ptr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < q; i++) {
        char c;
        int s, f;
        cin >> c >> s >> f;
        if (c == '?') {
            if(s == f) {
                cout << "YES" << '\n';
                continue;
            }

            int res = BFS(graph, s, f);
            if (res == INT_MAX) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
            }
        } else if(c == '-') {
            eraseV(graph, s, f);
            eraseV(graph, f, s);
        }
    }
}