#include <bits/stdc++.h>

using namespace std;

long double find_B(long double *arr, int n) {
    long double l = 0, r = arr[0];

    while (l < r - 0.000001) {
        bool f = true;
        arr[1] = (l + r) / 2;

        for(int i = 2; i < n; i++) {
            arr[i] = 2 * (arr[i-1] + 1) - arr[i-2];

            if(arr[i] < 0) {
                f = false;
                break;
            }
        }
        if(f) r = arr[1];
        else l = arr[1];
    }
    return arr[n - 1];
}


int main() {
    int n;
    long double A;

    cin>>n;
    long double arr[n];
    cin>>A;
    arr[0] = A;

    printf("%.2Lf", find_B(arr, n));
}