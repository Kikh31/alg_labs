#include <bits/stdc++.h>

using namespace std;

struct Elem {
    Elem *prev;
    long long st_max;
    long long val;

    explicit Elem(long long val0) : val(val0), prev(nullptr), st_max(0) {}
};

struct mystack {
    Elem *last;

    mystack() : last(nullptr) {}

    bool is_empty() {
        return last == nullptr;
    }

    long long get_max() {
        if (is_empty()) return -1;
        else return last->st_max;
    }

    void push(long long pval) {
        Elem *n = new Elem(pval);
        if (is_empty()) {
            n->st_max = pval;
            last = n;
            return;
        }
        n->prev = last;
        n->st_max = max(last->st_max, pval);
        last = n;
    }

    long long pop() {
        Elem *n = last;
        last = n->prev;

        long long ans = n->val;
        delete n;
        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    mystack s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char sign;
        long long k;

        cin >> sign;
        if (sign == '-') {
            s.pop();
        } else if (sign == '+') {
            cin >> k;
            s.push(k);
        } else {
            cout << s.get_max() << '\n';
            cin.get();
            cin.get();
        }
    }
}
