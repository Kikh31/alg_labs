#include <bits/stdc++.h>

using namespace std;

pair<int,int> partition(int *arr, int l, int r) {
    int p = arr[(l + r) / 2];

    while (l <= r) {
        while (arr[l] < p) l++;
        while (arr[r] > p) r--;

        if(l <= r) swap(arr[l++], arr[r--]);
    }
    return {l,r};
}

void orderStat(int *arr, int k, int l, int r) {
    pair<int,int> p = partition(arr, l, r);
    int pl = p.first;
    int pr = p.second;

    if (k < pl && k > pr) {
        cout<<arr[k];
        return;
    }
    else if (k <= pr && pr >= l) orderStat(arr, k, l, pr);
    else if (k >= pl && pl <= r) orderStat(arr, k, pl, r);
}

int main() {
    int n, k, A, B, C, a1, a2;
    cin >> n >> k;
    cin >> A >> B >> C >> a1 >> a2;

    int *arr = new int[n];
    arr[0] = a1;
    arr[1] = a2;

    for (int i = 2; i < n; i++) {
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
    }

    orderStat(arr, k-1, 0, n - 1);
}
