#include <bits/stdc++.h>

using namespace std;

struct Elem {
    Elem *prev;
    char val;

    explicit Elem(char val0) : val(val0), prev(nullptr) {}
};

struct mystack {
    Elem *last;

    mystack() : last(nullptr) {}

    bool is_empty() {
        return last == nullptr;
    }

    void push(char pval) {
        Elem *n = new Elem(pval);
        if (is_empty()) {
            last = n;
            return;
        } else {
            n->prev = last;
            last = n;
        }
    }

    char pop() {
        Elem *n = last;
        last = n->prev;

        char ans = n->val;
        delete n;

        return ans;
    }

    char check_last() {
        if (is_empty()) return 'n';
        else return last->val;
    }

    void clear() {
        while (!is_empty()) pop();
    }
};

int main() {
    mystack st;
    string c;

    while (cin >> c) {

        bool f = true;

        for (int i = 0; i < c.size(); i++) {
            if (c[i] == '(' || c[i] == '[') st.push(c[i]);
            else {
                if (st.check_last() == '(' && c[i] == ')') st.pop();
                else if (st.check_last() == '[' && c[i] == ']') st.pop();
                else {
                    f = false;
                    break;
                }
            }
        }
        if (f && st.is_empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        st.clear();
    }
}

