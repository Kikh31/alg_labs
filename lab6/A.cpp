#include <bits/stdc++.h>

using namespace std;

struct Node {
    int k;
    int l;
    int r;
    int h;
    int b;

    Node(int k = 0, int l = 0, int r = 0, int h = 0, int b = 0) : k(k), l(l), r(r), h(h), b(b) {}
};

void countHandB(Node *arr, int n) {
    for (int j = n - 1; j >= 0; j--) {

        if (arr[j].l + arr[j].r == 0) {
            arr[j].h = 1;
            arr[j].b = 0;
        }
        else if (arr[j].l == 0) {
            arr[j].h = arr[arr[j].r - 1].h + 1;
            arr[j].b = arr[arr[j].r - 1].h;
        } else if (arr[j].r == 0) {
            arr[j].h = arr[arr[j].l - 1].h + 1;
            arr[j].b = 0 - arr[arr[j].l - 1].h;
        } else if (arr[j].l != 0 && arr[j].r != 0) {
            arr[j].h = max(arr[arr[j].l - 1].h, arr[arr[j].r - 1].h) + 1;
            arr[j].b = arr[arr[j].r - 1].h - arr[arr[j].l - 1].h;
        }
    }
}

int main() {
    int n;
    cin >> n;

    Node arr[n];

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Node node(x, y, z);
        arr[i] = node;
    }
    countHandB(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i].b << '\n';
}
