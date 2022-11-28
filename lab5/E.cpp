#include <bits/stdc++.h>

using namespace std;

struct Node {
    string val;
    Node *left;
    Node *right;
    Node *parent;

    explicit Node(string val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct BinTree {
    Node *root;

    BinTree() : root(nullptr) {}

    bool exists(Node *r, string val) {
        if (r == nullptr) return false;

        if (r->val == val) return true;

        if (val < r->val) return exists(r->left, val);
        if (val > r->val) return exists(r->right, val);
    }

    void insert(Node *r, string val) {
        if (exists(root, val)) return;

        Node *node = new Node(val);

        if (root == nullptr) {
            root = node;
            return;
        }

        while (r != nullptr) {
            if (node->val > r->val) {
                if (r->right != nullptr) r = r->right;
                else {
                    node->parent = r;
                    r->right = node;
                    return;
                }
            } else {
                if (r->left != nullptr) r = r->left;
                else {
                    node->parent = r;
                    r->left = node;
                    return;
                }
            }
        }
    }

    void deleteN(string val) {
        Node *n = search(root, val);
        if (n == nullptr) return;

        if (n == root) {
            if (n->left == nullptr && n->right == nullptr) root = nullptr;

            else if (n->left == nullptr || n->right == nullptr) {
                if (n->left == nullptr) {
                    n->right->parent = nullptr;
                    root = n->right;
                } else {
                    n->left->parent = nullptr;
                    root = n->left;
                }
            } else {
                Node *suc = next(val);
                suc->left = root->left;
                root->left->parent = suc;
                root = root->right;
                root->parent = nullptr;
            }

        } else {
            Node *p = n->parent;

            if (n->left == nullptr && n->right == nullptr) {
                if (p->left == n) p->left = nullptr;
                if (p->right == n) p->right = nullptr;
            } else if (n->left == nullptr || n->right == nullptr) {
                if (n->left == nullptr) {
                    if (p->left == n) p->left = n->right;
                    else p->right = n->right;
                    n->right->parent = p;
                } else {
                    if (p->left == n) p->left = n->left;
                    else p->right = n->left;
                    n->left->parent = p;
                }
            } else {
                Node *suc = next(val);
                n->val = suc->val;
                if (suc->parent->left == suc) {
                    suc->parent->left = suc->right;
                    if (suc->right != nullptr)
                        suc->right->parent = suc->parent;
                } else {
                    suc->parent->right = suc->right;
                    if (suc->right != nullptr)
                        suc->right->parent = suc->parent;
                }
            }
        }
    }

    Node *search(Node *r, string val) {
        if (r == nullptr || val == r->val) return r;

        if (val < r->val) return search(r->left, val);
        else return search(r->right, val);
    }

    Node *next(string val) {
        Node *cur = root, *suc = nullptr;
        while (cur != nullptr) {
            if (cur->val > val) {
                suc = cur;
                cur = cur->left;
            } else cur = cur->right;
        }
        return suc;
    }
};

int main() {
    int n;
    string str;
    cin >> n;
    string a1[n], a2[n], a3[n];
    BinTree t1, t2, t3;
    int res1 = 0, res2 = 0, res3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        t1.insert(t1.root, a1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> a2[i];
        t2.insert(t2.root, a2[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> a3[i];
        t3.insert(t3.root, a3[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!t2.exists(t2.root, a1[i]) && !t3.exists(t3.root, a1[i])) {
            res1 += 3;
        } else if (t2.exists(t2.root, a1[i]) && !t3.exists(t3.root, a1[i])) {
            res1 += 1;
            res2 += 1;
        } else if (!t2.exists(t2.root, a1[i]) && t3.exists(t3.root, a1[i])) {
            res1 += 1;
            res3 += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!t1.exists(t1.root, a2[i]) && !t3.exists(t3.root, a2[i])) {
            res2 += 3;
        } else if (!t1.exists(t1.root, a2[i]) && t3.exists(t3.root, a2[i])) {
            res2 += 1;
            res3 += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!t1.exists(t1.root, a3[i]) && !t2.exists(t2.root, a3[i])) {
            res3 += 3;
        }
    }

    cout << res1 << " " << res2 << " " << res3;
}