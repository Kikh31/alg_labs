#include <iostream>

using std::cout, std::cin;

int hash(int x) {
    return (x + 10000000) % 1231231;
}

int main() {
    int n, ans = 0;
    cin >> n;
    int arr[n];
    int table[1231231] = {};

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        ans += table[hash(arr[i] - i)]++;
    }

    cout << ans << '\n';
}