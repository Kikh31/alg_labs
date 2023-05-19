#include <bits/stdc++.h>

using namespace std;

struct Edges {
    int start;
    int end;
    int weight;
};

const int INF = 1e7;

int n, k, v, e, negCycLen;

bool relax(int *d, int st, int ed, int w) {
    if (d[st] != INF && d[st] + w < d[ed]) {
        d[ed] = d[st] + w;
        return true;
    } else {
        return false;
    }
}

void negativeCycleCounter(vector<Edges> &edges, int *d) {
    for (auto &ed: edges) {
        bool relaxed = relax(d, ed.start, ed.end, ed.weight);
        if (relaxed) {
            negCycLen++;
        }
    }
}

void bellman(vector<Edges> &edges, int *d) {
    for (int ki = 0; ki < v - 1; ki++) {
        bool breaker = true;
        for (auto &ed: edges) {
            bool relaxed = relax(d, ed.start, ed.end, ed.weight);
            if (relaxed) {
                breaker = false;
            }
        }
        if (breaker) break;
    }

    negativeCycleCounter(edges, d);
}

int main() {

    cin >> n >> k;
    vector<Edges> edges;
    for (int i = 1; i <= n; i++) {
        cin >> v >> e;
        int d[v + 1];
        fill(d + 1, d + v + 1, INF);
        d[1] = 0;

        for (int j = 0; j < e; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }

        bellman(edges, d);

        if (negCycLen <= k) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        negCycLen = 0;
        edges.clear();
    }
}