#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = pow(10, 7);

int n, m, k;

void floyd(vector<vector<int> > &edges) {
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (int w = 1; w <= n; w++) {
                if (u == w) continue;

                if (abs(u - i) == k && abs(i - w) == k) {
                    edges[u][w] = min(edges[u][w], edges[u][i] + edges[i][w]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    vector<vector<int> > edges(n + 1, vector<int>(n + 1, INF));
    vector<vector<int> > next(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
    }

    floyd(edges);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (edges[x][y] == INF) {
            cout << -1 << '\n';
        } else {
            cout << edges[x][y] << '\n';
        }
    }
}