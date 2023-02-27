#include <bits/stdc++.h>

using namespace std;

struct Node {
    int k;
    int l;
    int r;

    Node(int k = 0, int l = 0, int r = 0) : k(k), l(l), r(r) {}
};

int get_height(Node *arr, int i, int res) {
    if (arr[i].l + arr[i].r == 0) return ++res;
    else if (arr[i].l == 0) return get_height(arr, arr[i].r - 1, res + 1);
    else if (arr[i].r == 0) return get_height(arr, arr[i].l - 1, res + 1);
    else if (arr[i].l != 0 && arr[i].r != 0)
        return max(get_height(arr, arr[i].l - 1, res + 1), get_height(arr, arr[i].r - 1, res + 1));

}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    Node arr[n];

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Node node(x, y, z);
        arr[i] = node;
    }

    for(int i = 0; i<n; i++) {
        cout << get_height(arr, i, 0);
    }

}