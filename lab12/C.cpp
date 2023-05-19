#include <iostream>

using std::cout, std::cin;

int hash(int x) {
    return x % 1000000;
}

int main() {
    int n;
    cin>>n;
    int table[1000000];

    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        table[hash(x)] = x;
    }

    for(int i = 0; i < n; i++) {
        int y;
        cin>>y;
        if(y != table[hash(y)]) {
            cout<<"NO"<<'\n';
            return 0;
        }
    }

    cout<<"YES"<<'\n';
}