#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];

    for (int i = 1; i <= n; i++) cin >> arr[i];

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (2 * i <= n && arr[i] > arr[2 * i]) {
            flag = false;
            break;
        }
        if (2 * i + 1 <= n && arr[i] > arr[2 * i + 1]) {
            flag = false;
            break;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";
}