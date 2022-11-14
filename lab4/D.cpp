#include <bits/stdc++.h>

using namespace std;

void countingSort(string *arr, int n, int div) {
    int k = -1;
    for (int i = 0; i < n; i++) {
        k = max(k, arr[i][div] + 1);
    }

    int C[k] = {0};
    for (int i = 0; i < n; ++i) C[arr[i][div]]++;

    for (int i = 1; i < k; ++i) {
        C[i] += C[i - 1];
    }

    string resArr[n];
    for (int i = n - 1; i >= 0; --i) {
        resArr[C[arr[i][div]] - 1] = arr[i];
        C[arr[i][div]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = resArr[i];
    }
}

void radixSort(string *arr, int n, int m, int k) {
    for(int i = m - 1; i >= m - k; i--) {
        countingSort(arr, n, i);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    radixSort(arr, n, m, k);
    for(int i = 0; i < n; i++) cout<<arr[i]<<endl;
}
