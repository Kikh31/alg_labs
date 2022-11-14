#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, n;
    cin>>s>>n;
    vector< pair<int, int> > v;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back( {x, y} );
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && v[j - 1].second < v[j].second; j--) {
            swap(v[j - 1], v[j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && v[j - 1].first > v[j].first; j--) {
            swap(v[j - 1], v[j]);
        }
    }

    for (auto x : v) {
        if(s <= x.first) {
            cout<<"NO";
            return 0;
        }
        s+=x.second;
    }
    cout<<"YES";
}
