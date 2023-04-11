#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum class Color {
    White, Grey, Black
};

int n, m, q, cmpCount;
stack<int> vs;

void dfsG(vector<vector<int> > &graphG, int u, Color *color) {
    color[u] = Color::Grey;
    for (auto v: graphG[u]) {
        if (color[v] == Color::White) {
            dfsG(graphG, v, color);
        }

    }
    color[u] = Color::Black;
    vs.push(u);
}

void dfsH(vector<vector<int> > &graphH, int u, int *comps) {
    comps[u] = cmpCount;
    for (auto v: graphH[u]) {
        if (comps[v] == 0) {
            dfsH(graphH, v, comps);
        }
    }
}

int main() {

    cin >> n >> m >> q;
    vector<vector<int> > graphG(n + 1);
    vector<vector<int> > graphH(n + 1);
    Color color[n + 1];
    fill(color + 1, color + n + 1, Color::White);
    int comps[n + 1];
    fill(comps + 1, comps + n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graphG[x].push_back(y);
        graphH[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == Color::White) dfsG(graphG, i, color);
    }
    cmpCount = 1;
    while (!vs.empty()) {
        int u = vs.top();
        vs.pop();
        if (comps[u] == 0) {
            dfsH(graphH, u, comps);
            cmpCount++;
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (comps[x] == comps[y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
