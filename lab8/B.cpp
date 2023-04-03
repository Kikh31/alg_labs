#include <bits/stdc++.h>

using namespace std;

enum class Color {
    White, Grey, Black
};

int n, m;
bool final = false;

void Visit(vector<vector<int>> &graph, Color *color, int u, int prev) {
    color[u] = Color::Grey;
    for (auto v: graph[u]) {
        if (color[v] == Color::White) {
            Visit(graph, color, v, u);
        }

        if (color[v] == Color::Grey && v != u && v != prev) {
            final = true;
        }
    }
    color[u] = Color::Black;
}

void DFS(vector<vector<int>> &graph, Color *color) {
    for (int i = 1; i <= n; i++) {
        color[i] = Color::White;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == Color::White) {
            Visit(graph, color, i, 0);
        }
    }
}


int main() {
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    Color color[n + 1];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, color);
    if (final) cout << "YES";
    else cout << "NO";
}