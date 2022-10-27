#include <iostream>

using namespace std;


int left_binSearch(int *arr, int size, int key) {
    int l = -1;
    int r = size;

    while (l < r - 1) {
        int mid = (l + r) / 2;

        if (arr[mid] < key) l = mid;
        else r = mid;
    }
    if (arr[r] == key) return r + 1;
    else return -1;
}

int right_binSearch(int *arr, int size, int key) {
    int l = -1;
    int r = size;

    while (l < r - 1) {
        int mid = (l + r) / 2;

        if (arr[mid] <= key) l = mid;
        else r = mid;
    }
    if (arr[l] == key) return l + 1;
    else return -1;
}

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> m;
    int searchArr[m];
    for (int i = 0; i < m; i++) cin >> searchArr[i];

    for (int i = 0; i < m; i++) {
        cout << left_binSearch(arr, n, searchArr[i]) << " " << right_binSearch(arr, n, searchArr[i]) << '\n';
    }
}
