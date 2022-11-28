#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *parent;

    explicit Node(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct BinTree {
    Node *root;

    BinTree() : root(nullptr) {}

    bool exists(Node *r, int val) {
        if (r == nullptr) return false;

        if (r->val == val) return true;

        if (val < r->val) return exists(r->left, val);
        if (val > r->val) return exists(r->right, val);
    }

    void insert(Node *r, int val) {
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

    void deleteN(int val) {
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

    Node *search(Node *r, int val) {
        if (r == nullptr || val == r->val) return r;

        if (val < r->val) return search(r->left, val);
        else return search(r->right, val);
    }

    Node *next(int val) {
        Node *cur = root, *suc = nullptr;
        while (cur != nullptr) {
            if (cur->val > val) {
                suc = cur;
                cur = cur->left;
            } else cur = cur->right;
        }
        return suc;
    }

    Node *prev(int val) {
        Node *cur = root, *suc = nullptr;
        while (cur != nullptr) {
            if (cur->val >= val) {
                cur = cur->left;
            } else {
                suc = cur;
                cur = cur->right;
            }
        }
        return suc;
    }

    void postorderTraversal(Node *r) {
        if(r!= nullptr) {
            postorderTraversal(r->left);
            postorderTraversal(r->right);
            cout<<r->val<<" ";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    BinTree tree;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        tree.insert(tree.root, x);
    }

    tree.postorderTraversal(tree.root);
}