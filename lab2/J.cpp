#include <bits/stdc++.h>

using namespace std;

void antiQuickSort(int *arr, int n) {
    for (int i = 2; i < n; i++) {
        swap(arr[i], arr[i / 2]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) arr[i] = i + 1;

    antiQuickSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}