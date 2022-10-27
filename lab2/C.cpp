#include <iostream>

using namespace std;

bool comp(int x, int y, bool greater) {
    return greater ? x < y : x > y;
}

void insertionSort(int *arr, size_t n, bool greater = false) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && comp(arr[j - 1], arr[j], greater); j--) {
            swap(arr[j - 1], arr[j]);
        }
    }
}

int main() {
    int n, m, k, res = 0;
    cin >> n >> m;
    int plots[n * m];
    //int _plots[n*m];
    for (int i = 0; i < n * m; i++) {
        cin >> plots[i];
    }

    cin >> k;
    int k_arr[k];
    for (int i = 0; i < k; i++) cin >> k_arr[i];

    insertionSort(plots, n * m, true);
    insertionSort(k_arr, k, true);

    int last_j = 0;
    for (int i = 0; i < n * m; i++) {
        for (int j = last_j; j < k; j++) {
            if (k_arr[j] > plots[i]) continue;
            last_j = j + 1;
            res++;
            break;
        }
    }
    cout << res;
}


