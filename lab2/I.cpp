#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int l, int r) {
    int p = arr[(l + r) / 2];

    while (l <= r) {
        while (arr[l] < p) l++;
        while (arr[r] > p) r--;

        if (l >= r) break;

        swap(arr[l++], arr[r--]);
    }
    return r;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
