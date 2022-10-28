#include <bits/stdc++.h>

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
    string c;
    mystack st;

    getline(cin, c);

    for (int i = 0; i < c.size(); i++) {
        if (c[i] == ' ') continue;

        if (c[i] == '+') {
            int res = st.pop() + st.pop();
            st.push(res);
        } else if (c[i] == '-') {
            int r2 = st.pop(), r1 = st.pop();
            int res = r1 - r2;
            st.push(res);
        } else if (c[i] == '*') {
            int res = st.pop() * st.pop();
            st.push(res);
        } else {
            st.push(c[i] - '0');
        }
    }

    cout << st.pop();
}