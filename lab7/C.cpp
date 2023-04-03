#include <iostream>
#include <cmath>

using namespace std;

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

string inspectMsg(string s) {
    int n = 1 << (int)log2(s.size());
    int mistakes = 0;
    for(int i = 1; i <= n; i <<= 1) {
        int c = 0;
        int steps = 0;
        for(int j=i; j <= s.size(); j++) {
            steps++;
            c += (s[j-1]=='1') ? 1 : 0;
            if(steps == i) {
                j += i;
                steps = 0;
                continue;
            }

        }
        if(c%2==1) {
            mistakes+=i;
        }
    }
    if(mistakes!=0) {
        if(s[mistakes-1]=='0') s[mistakes-1] = '1';
        else s[mistakes-1] = '0';
    }
    return delBits(s);
}

int main() {
    int n;
    cin>>n;
    string arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    for(int i = 0; i < n; i++) cout<<inspectMsg(arr[i])<<'\n';
}
