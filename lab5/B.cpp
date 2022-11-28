#include <iostream>

using namespace std;

struct Node {
    int k;
    int l;
    int r;
};

bool isBinTree(Node *arr, int i, int min, int max) {
    if (arr[i].k <= min || arr[i].k >= max) return false;
    if (arr[i].l + arr[i].r == 0) return true;
    else if (arr[i].l == 0) return isBinTree(arr, arr[i].r - 1, arr[i].k, max);
    else if (arr[i].r == 0) return isBinTree(arr, arr[i].l - 1, min, arr[i].k);
    else if (arr[i].l != 0 && arr[i].r != 0)
        return isBinTree(arr, arr[i].l - 1, min, arr[i].k) && isBinTree(arr, arr[i].r - 1, arr[i].k, max);
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    Node arr[n];

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Node node;
        node.k = x;
        node.l = y;
        node.r = z;
        arr[i] = node;
    }

    if (isBinTree(arr, 0, -INT_MAX, INT_MAX)) {
        cout << "YES";
    }
    else cout << "NO";
}