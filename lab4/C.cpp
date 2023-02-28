#include <iostream>
#include <vector>

using namespace std;

struct priorityQueue {
    vector< pair<int, int> > vec;
    int oper = 0;

    void siftDown(int n, int i) {
        while (2 * i + 1 < n) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int min = l;
            if (r < n && vec[r].first < vec[min].first) min = r;

            if (vec[i].first <= vec[min].first) break;
            swap(vec[i], vec[min]);
            i = min;
        }
    }

    void siftUp(int i) {
        while (vec[i].first < vec[(i - 1) / 2].first) {
            swap(vec[i], vec[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void push(int val) {
        vec.push_back( make_pair(val, ++oper) );
        int n = vec.size() - 1;
        siftUp(n);
    }

    void extract_min() {
        oper++;
        if(!vec.empty()) {
            int min = vec[0].first;
            swap(vec[0], vec[vec.size()-1]);
            vec.pop_back();
            siftDown(vec.size(), 0);
            cout<<min<<endl;
        } else {
            cout<<'*'<<endl;
        }
    }

    void decrease_key(int x, int y) {
        oper++;
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i].second == x) {
                vec[i].first = y;
                siftUp(i);
            }
        }
    }
};

int main() {
    priorityQueue q;
    string cmd;
    while (cin>>cmd) {
        if(cmd == "push") {
            int val;
            cin>>val;
            q.push(val);
        }
        else if(cmd == "extract-min") q.extract_min();
        else if(cmd == "decrease-key") {
            int x, y;
            cin>>x>>y;
            q.decrease_key(x,y);
        }
    }
}