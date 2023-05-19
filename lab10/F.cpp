#include <bits/stdc++.h>

using namespace std;

int n, m, q;

struct Request {
    char sign;
    int start;
    int finish;
};

struct DSU {
    int *parent;
    int *rank;

    DSU(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        fill(rank + 1, rank + n + 1, 0);
    }

    int findSet(int v) {
        if (v == parent[v]) return v;

        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int x, int y) {
        x = findSet(x);
        y = findSet(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
};

void eraseV(vector<vector<int> > &graph, int s, int f) {
    int ptr = 0;
    while (graph[s][ptr] != f) ptr++;
    graph[s].erase(graph[s].begin() + ptr);
}

int main() {
    cin >> n >> m >> q;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    DSU dsu = DSU(n);
    stack<Request> requests;

    for (int i = 0; i < q; i++) {
        char c;
        int s, f;
        cin >> c >> s >> f;

        if (c == '-') {
            eraseV(graph, s, f);
            eraseV(graph, f, s);
        }

        requests.push({c, s, f});
    }

    for (int i = 1; i <= n; i++) {
        for (auto &v: graph[i]) {
            dsu.unionSets(i, v);
        }
    }

    stack<string> ans;

    while (!requests.empty()) {
        Request req = requests.top();
        requests.pop();

        if (req.sign == '-') {
            dsu.unionSets(req.start, req.finish);
        } else if (req.sign == '?') {
            if (dsu.findSet(req.start) == dsu.findSet(req.finish)) {
                ans.push("YES");
            } else {
                ans.push("NO");
            }
        }
    }

    while (!ans.empty()) {
        cout<<ans.top()<<'\n';
        ans.pop();
    }
}