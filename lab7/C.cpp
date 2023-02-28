#include <iostream>
#include <cmath>

using namespace std;

bool isCorrect(string s, int index) {

}

string inspectMsg(string s) {
    int n = 1 << (int)log2(s.size());

    for(int i = 1; i <= n; i <<= 1) {
        int c = 0;
        int steps = i;
        for(int j=i; j < s.size(); j++) {
            if(steps != i) {
                steps++;
                continue;
            }
            c += (s[j]=='1') ? 1 : 0;
            cout<<s[j];
            cout<<" ";
        }
    }
}

string delBits(string s) {
    string res="";

    for(int i = 0; i < s.size(); i++) {
        bool f = true;
        int n = 1 << (int)log2(s.size());

        for(int j = 1; j <= n; j <<= 1) {
            if( i == j - 1 ) {
                f = false;
                break;
            }
        }
        if(f) res+=s[i];
    }

    return res;
}

int main() {
    int n;
    cin>>n;
    string arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    for(int i = 0; i < n; i++) cout<<decode(arr[i])<<'\n';
}
