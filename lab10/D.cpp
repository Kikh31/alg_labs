#include <bits/stdc++.h>

using namespace std;

struct Edges {
    int start;
    int end;
    int weight;
};

const int INF = 1e7;

int n, m, q, strt;

bool relax(int *d, int st, int ed, int w) {
    if(d[st] != INF && d[st] + w < d[ed]) {
        d[ed] = d[st] + w;
        return true;
    } else {
        return false;
    }
}

void bellman(vector<Edges> &edges, int *d) {
    for(int k = 0; k < n-1; k++) {
        bool breaker = true;
        for(auto &e : edges) {
            bool relaxed = relax(d, e.start, e.end, e.weight);
            if(relaxed) {
                breaker = false;
            }
        }
        if(breaker) break;
    }
}

int main() {

    cin>>n>>m>>q>>strt;
    vector<Edges> edges;

    int d[n+1];
    fill(d+1, d+n+1, INF);
    d[strt] = 0;

    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
        edges.push_back({y,x,z});
    }

    bellman(edges, d);

    for(int i = 0; i < q; i++) {
        int a;
        cin>>a;
        if(d[a] == INF) {
            cout<<-1<<'\n';
        } else {
            cout<<d[a]<<'\n';
        }
    }
}
