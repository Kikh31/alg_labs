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

    void clear() {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        fill(rank + 1, rank + n + 1, 0);
    }
};

int main() {
    long long res1 = 0;
    cin>>n>>m;
    DSU dsu(n);

    vector<Edges> edges;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
    }

    sort(edges.begin(), edges.end(), comp);

    int passed = 0, i = 0;
    bool once = true;

    for(auto v : edges) {
        if(dsu.findSet(v.start) != dsu.findSet(v.end)) {
            res1 += v.weight;
            dsu.unionSets(v.start, v.end);
            i++;
        } else if(once) {
            passed = i;
            once = false;
        }
    }

    dsu.clear();
    long long res2 = edges[passed].weight;
    dsu.unionSets(edges[passed].start, edges[passed].end);

    for(auto v : edges) {
        if(dsu.findSet(v.start) != dsu.findSet(v.end)) {
            res2 += v.weight;
            dsu.unionSets(v.start, v.end);
        }
    }

    cout<<'\n';

    cout<<res1<<" "<<res2;
}