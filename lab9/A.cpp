#include <iostream>
#include <vector>
using namespace std;

enum class Color {
    White, Grey, Black
};

int n, m, ans1;

void Visit(vector<vector<int> > &graph, Color *color, int u, int *conComps, int *traps, int *compTraps) {
    color[u] = Color::Grey;
    conComps[u] = ans1;
    if (traps[u] == 1) {
        compTraps[ans1] = 1;
    }

    for (auto v: graph[u]) {
        if (color[v] == Color::White) {
            Visit(graph, color, v, conComps, traps, compTraps);
        }
    }
    color[u] = Color::Black;
}

void DFS(vector<vector<int> > &graph, Color *color, int *conComps, int *traps, int *compTraps) {
    for (int i = 1; i <= n; i++) {
        color[i] = Color::White;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == Color::White) {
            ans1++;
            Visit(graph, color, i, conComps, traps, compTraps);
        }
    }
}

int main() {
    cin>>n>>m;

    vector< vector<int> > graph(n + 1);
    Color color[n + 1];
    int conComps[n + 1];
    int traps[n+1];
    int compTraps[n+1];
    fill(compTraps+1, compTraps+n+1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <=n; i++) {
        cin>>traps[i];
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, color, conComps, traps, compTraps);
    cout<<ans1<<'\n';
    for(int i = 1; i <= n; i++) {
        cout<<conComps[i]<<" ";
    }
    cout<<'\n';
    for(int i = 1; i <=ans1; i++) {
        cout<<compTraps[i]<<" ";
    }
}