#include <bits/stdc++.h>

using namespace std;

void buildCode(int n, int **GrayCode) {
    GrayCode[0][n - 1] = 0;
    GrayCode[1][n - 1] = 1;
    int p = 2;
    for (int i = 2; i <= n; i++) {
        int t = p - 1;
        p *= 2;
        for (int k = p / 2; k < p; k++) {

            for (int j = 0; j < n; j++) {
                GrayCode[k][j] = GrayCode[t][j];
            }

            GrayCode[t][n - i] = 0;
            GrayCode[k][n - i] = 1;
            t--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int **GrayCode = new int *[1 << n];
    for (int i = 0; i < 1 << n; i++) {
        GrayCode[i] = new int[n];
    }
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            GrayCode[i][j] = 0;
        }
    }

    buildCode(n, GrayCode);
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            cout << GrayCode[i][j];
        }
        cout << '\n';
    }
}