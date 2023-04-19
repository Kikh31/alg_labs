#include <iostream>
#include <vector>

using namespace std;

const int INF = pow(10, 7);

int n, m;

void floyd(vector<vector<int> > &edges) {
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (int w = 1; w <= n; w++) {
                if (u == w) continue;
                edges[u][w] = min(edges[u][w], edges[u][i] + edges[i][w]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int> > edges(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }

    floyd(edges);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || edges[i][j] == INF) continue;

            res = max(res, edges[i][j]);
        }
    }
    cout << res;
}
