#include <bits/stdc++.h>

using namespace std;

struct arrNode {
    int k;
    int l;
    int r;

    explicit arrNode(int k = 0, int l = 0, int r = 0) : k(k), l(l), r(r) {}
};

struct Node {
    Node *l;
    Node *r;
    int k;
    int h;

    Node(int k = 0, Node *l = nullptr, Node *r = nullptr, int h = 1) : k(k), l(l), r(r), h(h) {}
};

int height(Node *n) {
    if (n != nullptr) return n->h;
    else return 0;
}

int bfactor(Node *n) {
    return height(n->r) - height(n->l);
}

void fixheight(Node *n) {
    int hl = height(n->l);
    int hr = height(n->r);
    n->h = max(hl, hr) + 1;
}

Node *rotateR(Node *p) {
    Node *q = p->l;
    p->l = q->r;
    q->r = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node *rotateL(Node *q) {
    Node *p = q->l;
   q->l = p->r;
    p->r = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node *balance(Node *p) {
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->r) < 0) p->r = rotateR(p->r);
        return rotateL(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->l) > 0) p->r = rotateL(p->l);
        return rotateR(p);
    }
    return p;
}

Node *insert(Node *p, int k) {
    if (p == nullptr) return new Node(k);
    if (k < p->k) p->l = insert(p->l, k);
    else if (k > p->k) p->r = insert(p->r, k);
    return balance(p);
}

void mkChain(Node* root, arrNode* arr, int i) {
    Node* newN = insert(root, arr[i].k);
    if(arr[i].l + arr[i].r == 0) return;

    if(arr[i].l==0) mkChain(newN, arr, arr[i].r-1);
    else if(arr[i].r==0) mkChain(newN, arr, arr[i].l-1);
    else {
        mkChain(newN, arr, arr[i].l-1);
        mkChain(newN, arr, arr[i].r-1);
    }
}

void mkTreeFromArr(arrNode* arr) {
    Node *root = insert(nullptr, arr[0].k);
    if (arr[0].l + arr[0].r == 0) return;

    if (arr[0].l == 0) mkChain(root, arr, arr[0].r-1);
    else if (arr[0].r == 0) mkChain(root, arr, arr[0].l-1);
    else {
        mkChain(root, arr, arr[0].l-1);
        mkChain(root, arr, arr[0].r-1);
    }
}




int main() {
    int n;
    cin >> n;

    arrNode arr[n];

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arrNode arrNode(x, y, z);
        arr[i] = arrNode;
    }

    mkTreeFromArr(arr);
}