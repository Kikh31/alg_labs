#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {1, 2, 3, 9, 12},
            b[] = {6, 10};

    int a_size = sizeof(a) / sizeof(int),
            b_size = sizeof(b) / sizeof(int),
            i = 0, j = 0, r1, r2, _min = INT_MAX;

    while (i < a_size && j < b_size) {
        if (abs(a[i] - b[j]) < _min) {
            _min = abs(a[i] - b[j]);
            r1 = min(a[i], b[j]);
            r2 = max(a[i], b[j]);
        }

        if (_min == 0) break;

        if (a[i] < b[j]) i++;
        else j++;
    }

    cout << r1 << " " << r2;
}
