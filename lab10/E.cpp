#include <bits/stdc++.h>

using namespace std;

struct Edges {
    int start;
    int end;
    int weight;
};

const int INF = 1e7;

int n, m, start, finish;

bool relax(int *d, int st, int ed, int w) {
    if (d[st] != INF && d[st] + w < d[ed]) {
        d[ed] = d[st] + w;
        return true;
    } else {
        return false;
    }
}

void bellman(vector<Edges> &edges, int *d) {
    for (int k = 0; k < n - 1; k++) {
        bool breaker = true;
        for (auto &e: edges) {
            bool relaxed = relax(d, e.start, e.end, e.weight);
            if (relaxed) {
                breaker = false;
            }
        }
        if (breaker) break;
    }
}

int main() {

    cin >> n >> m >> start >> finish;
    vector<Edges> edges;

    int d[n + 1];
    fill(d + 1, d + n + 1, INF);
    d[start] = 0;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }

    bellman(edges, d);

    if (d[finish] == INF) {
        cout << -1;
    } else {
        cout << d[finish];
    }
}