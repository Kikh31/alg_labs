#include <bits/stdc++.h>

using namespace std;

void merge(vector<pair<int, int>> &arr, int l, int m, int r) {
    int nl = m - l + 1;
    int nr = r - m;
    vector<pair<int, int>> larr, rarr;

    for (int i = 0; i < nl; i++) larr.push_back(arr[l + i]);
    for (int i = 0; i < nr; i++) rarr.push_back(arr[m + 1 + i]);

    int i = 0, j = 0, k = l;
    while (i < nl && j < nr) {
        if (larr[i].second <= rarr[j].second) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int, int>> &arr, int l, int r) {

    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }

    mergeSort(v, 0, n - 1);

    int li = v[n - 1].first;
    int ri = v[n - 1].second;
    int res = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (li <= v[i].second) li = min(v[i].first, li);
        else {
            res += ri - li + 1;
            li = v[i].first;
            ri = v[i].second;
        }
    }
    res += ri - li + 1;

    cout << res;
}