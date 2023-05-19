#include <iostream>

using std::cin, std::cout, std::fill;

int hash(int key) {
    return key % 123121;
}

void insert(int key, int *table) {
    int x = hash(key);
    while(true) {
        if(table[x] == -1) {
            table[x] = key;
            return;
        } else {
            x = (x + 1) % 123121;
        }
    }
}

bool search(int key, const int *table) {
    int x = hash(key);
    while(true) {
        if(table[x] == key) {
            return true;
        } else {
            if(table[x] == -1) {
                return false;
            } else {
                x = (x + 1) % 123121;
            }
        }
    }
}

int main() {
    int n, res = 0;
    cin >> n;
    int x_table[123121];
    int y_table[123121];
    fill(x_table, x_table+123121, -1);
    fill(y_table, y_table+123121, -1);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        if(!search(x, x_table) && !search(y, y_table)) {
            res++;
            insert(x, x_table);
            insert(y, y_table);
        }

        if(res > 3) {
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    if(res == 3) {
        cout<<"YES"<<'\n';
    } else {
        cout<<"NO"<<'\n';
    }
}