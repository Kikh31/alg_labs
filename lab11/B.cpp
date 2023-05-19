#include <bits/stdc++.h>

using namespace std;

int n, m;

struct Edges {
    int start;
    int end;
    int weight;
};

bool comp(Edges &a, Edges &b) {
    return a.weight < b.weight;
}

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

int main() {
    long long res = 0;
    cin>>n>>m;
    DSU dsu(n);

    vector<Edges> edges;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
    }

    sort(edges.begin(), edges.end(), comp);

    for(auto v : edges) {
        if(dsu.findSet(v.start) != dsu.findSet(v.end)) {
            res += v.weight;
            dsu.unionSets(v.start, v.end);
        }
    }

    cout<<res;
}