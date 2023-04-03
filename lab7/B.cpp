#include <iostream>

using namespace std;

int res;
pair<char, int> cur(' ', 0);

int comp(string s1, string s2) {
    char c1 = s1[0];
    char c2 = s2[0];
    int i1 = stoi(s1.substr(1, s1.size() - 1));
    int i2 = stoi(s2.substr(1, s2.size() - 1));

    if (cur.second == 0) {
        if (c1 != c2) res += min(i1, i2);

        if (i1 > i2) {
            cur.first = c1;
            cur.second = i1 - i2;
            return 2;
        } else if (i1 < i2) {
            cur.first = c2;
            cur.second = i2 - i1;
            return 1;
        } else if (i1 == i2) {
            cur.second = 0;
            return 0;
        }
    } else if (cur.second != 0 && cur.first == c1) {
        if (cur.first != c2) res += min(cur.second, i2);

        if (cur.second > i2) {
            cur.second -= i2;
            return 2;
        } else if (cur.second < i2) {
            cur.first = c2;
            cur.second = i2 - cur.second;
            return 1;
        } else if (cur.second == i2) {
            cur.second = 0;
            return 0;
        }
    } else if (cur.second != 0 && cur.first == c2) {
        if (cur.first != c1) res += min(cur.second, i1);

        if (cur.second > i1) {
            cur.second -= i1;
            return 1;
        } else if (cur.second < i1) {
            cur.first = c1;
            cur.second = i1 - cur.second;
            return 2;
        } else if (cur.second == i1) {
            cur.second = 0;
            return 0;
        }
    }
}

int main() {
    long long n, m, k;

    string s1, s2;

    cin >> n >> m >> k >> s1 >> s2;

    int l1 = 0, r1 = 1, l2 = 0, r2 = 1;
    while (true) {
        while (s1[r1] >= '0' && s1[r1] <= '9') r1++;
        while (s2[r2] >= '0' && s2[r2] <= '9') r2++;

        int mv = comp(s1.substr(l1, r1 - l1), s2.substr(l2, r2 - l2));

        if (r1 == n && r2 == m) {
            cout << res << '\n';
            if (res < k) cout << "Yes";
            else cout << "No";
            return 0;
        }

        if (mv == 1 && r1 < n) l1 = r1++;
        else if (mv == 2 && r2 < m) l2 = r2++;
        else {
            if (r1 < n) l1 = r1++;
            if (r2 < m) l2 = r2++;
        }

    }
}

/*#include <bits/stdc++.h>

using namespace std;

int res;

void comp(string &s1, string &s2, int k) {
    char c1, c2;
    int i1 = 0, i2 = 0;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < s1.size() || ptr2 < s2.size()) {
        if (i1 == 0) {
            c1 = s1[ptr1];
            ptr1++;
            while (s1[ptr1] >= '0' && s1[ptr1] <= '9') {
                i1 = i1 * 10 + (int) (s1[ptr1] - '0');
                ptr1++;
            }
        }
        if (i2 == 0) {
            c2 = s2[ptr2];
            ptr2++;
            while (s2[ptr2] >= '0' && s2[ptr2] <= '9') {
                i2 = i2 * 10 + (int) (s2[ptr2] - '0');
                ptr2++;
            }
        }

        if (c1 != c2) {
            res += min(i1, i2);
        }

        int cpy = min(i1, i2);
        i1 -= cpy;
        i2 -= cpy;
    }

}

int main() {
    int n, m, k;
    string s1, s2;
    cin >> n >> m >> k >> s1 >> s2;

    comp(s1, s2, k);
    if (res < k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}*/