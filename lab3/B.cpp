#include <iostream>

using namespace std;

struct Elem {
    Elem *next;
    Elem *prev;
    int val;

    explicit Elem(int val0) : val(val0), prev(nullptr), next(nullptr) {}
};

struct mystack {
    Elem *first;
    Elem *last;

    mystack() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int pval) {
        Elem *n = new Elem(pval);
        if (is_empty()) {
            first = n;
            last = n;
            return;
        } else {
            last->next = n;
            n->prev = last;
            last = n;
        }
    }

    int pop_front() {
        Elem *n = first;
        first = n->next;

        int ans = n->val;
        delete n;

        return ans;
    }

    int pop_back() {
        if (first == last) {
            return pop_front();
        }

        Elem *n = last;
        last = n->prev;

        int ans = n->val;
        delete n;

        return ans;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    mystack s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char sign;
        int k;

        cin >> sign;
        if (sign == '-') {
            cout << s.pop_back() << '\n';
        } else {
            cin >> k;
            s.push_back(k);
        }
    }
}
