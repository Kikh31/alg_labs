#include <iostream>

using namespace std;

struct Elem {
    Elem* next;
    int val;

    explicit Elem(int val0) : val(val0), next(nullptr) {}
};

struct myqueue {
    Elem* first;
    Elem* last;

    myqueue() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int pval) {
        Elem* n = new Elem(pval);
        if(is_empty()) {
            first = n;
            last = n;
            return;
        } else {
            last->next = n;
            last = n;
        }
    }

    int pop_front() {
        Elem* n = first;
        first = n->next;

        int ans = n->val;
        delete n;

        return ans;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    myqueue q;
    cin>>n;

    for(int i = 0; i < n; i++) {
        char sign;
        int k;

        cin>>sign;
        if(sign == '-') {
            cout<<q.pop_front()<<'\n';
        } else {
            cin>>k;
            q.push_back(k);
        }
    }
}
