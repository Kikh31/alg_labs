#include <bits/stdc++.h>

using namespace std;

struct Node {
    int k;
    int l;
    int r;
    int c;
    int cl;

    Node(int k = 0, int l = 0, int r = 0, int c = 0, int cl = 0) : k(k), l(l), r(r), c(c), cl(cl) {}
};

void countNods(Node *arr, int n) {
    for (int j = n - 1; j >= 0; j--) {

        if (arr[j].l + arr[j].r == 0) arr[j].c = 0;
        else if (arr[j].l == 0) arr[j].c = arr[arr[j].r - 1].c + 1;
        else if (arr[j].r == 0) arr[j].c = arr[arr[j].l - 1].c + 1;
        else if (arr[j].l != 0 && arr[j].r != 0) {
            arr[j].c = arr[arr[j].l - 1].c + arr[arr[j].r - 1].c + 2;
        }

        if (arr[j].l == 0) arr[j].cl = 0;
        else {
            arr[j].cl = arr[arr[j].l - 1].c + 1;
        }
    }
}


void getBinTreeKeys(Node *arr, int i, int l) {
    arr[i].k = l + arr[i].cl + 1;
    if (arr[i].l + arr[i].r == 0) return;
    else if (arr[i].l == 0) getBinTreeKeys(arr, arr[i].r - 1, arr[i].k);
    else if (arr[i].r == 0) getBinTreeKeys(arr, arr[i].l - 1, l);
    else if (arr[i].l != 0 && arr[i].r != 0) {
        getBinTreeKeys(arr, arr[i].l - 1, l);
        getBinTreeKeys(arr, arr[i].r - 1, arr[i].k);
    }
}

int main() {
    int n;
    cin >> n;
    Node arr[n];

    for (int i = 0; i < n; i++) {
        int y, z;
        cin >> y >> z;
        Node node(0, y, z);
        arr[i] = node;
    }

    countNods(arr, n);
    getBinTreeKeys(arr, 0, 0);

    for (int i = 0; i < n; i++) cout << arr[i].k << " ";
}