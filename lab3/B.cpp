#include <iostream>
#include <vector>

using namespace std;

struct Elem {
    Elem *prev;
    int val;

    explicit Elem(int val0) : val(val0), prev(nullptr) {}
};

struct mystack {
    Elem *last;

    mystack() : last(nullptr) {}

    bool is_empty() {
        return last == nullptr;
    }

    void push(int pval) {
        Elem *n = new Elem(pval);
        if (is_empty()) {
            last = n;
            return;
        } else {
            n->prev = last;
            last = n;
        }
    }

    int pop() {
        Elem *n = last;
        last = n->prev;

        int ans = n->val;
        delete n;

        return ans;
    }
};

int main() {
    int n;
    vector<int> res;
    mystack s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char sign;
        int k;

        cin >> sign;
        if (sign == '-') {
            res.push_back(s.pop());
        } else {
            cin >> k;
            s.push(k);
        }
    }

    for (auto x : res) cout << x << '\n';
}
