#include <bits/stdc++.h>

using namespace std;

int res;
pair<char, int> cur = {' ', 0};

int comp(string s1, string s2) {
    char c1 = s1[0];
    char c2 = s2[0];
    int i1 = stoi(s1.substr(1, s1.size()-1 ) );
    int i2 = stoi(s2.substr(1, s2.size()-1 ) );
    //cout<<c1<<i1<<" "<<c2<<i2<<" "<<cur.first<<cur.second<<'\n';

    if(cur.second == 0) {
        if(i1 > i2) {
            if(c1 != c2) res+=i2;
            cur.first = c1;
            cur.second = i1 - i2;
            return 2;
        } else if(i1 < i2) {
            if(c1 != c2) res+=i1;
            cur.first = c2;
            cur.second = i2 - i1;
            return 1;
        } else {
            if(c1 != c2) res+=i1;
            cur.first = ' ';
            cur.second = 0;
            return 0;
        }
    } else if(cur.first == c1) {
        if(cur.second > i2) {
            if(cur.first!=c2) res+=i2;
            cur.second -= i2;
            return 2;
        } else if(cur.second < i2){
            if(cur.first!=c2) res+=cur.second;
            cur.first = c2;
            cur.second = i2 - cur.second;
            return 1;
        } else {
            if(cur.first!=c2) res+=cur.second;
            cur.first = ' ';
            cur.second = 0;
            return 0;
        }
    } else if(cur.first == c2) {
        if(cur.second > i1) {
            if(cur.first!=c1) res+=i1;
            cur.second -= i1;
            return 1;
        } else if(cur.second < i1){
            if(cur.first!=c1) res+=cur.second;
            cur.first = c1;
            cur.second = i1 - cur.second;
            return 2;
        } else {
            if(cur.first!=c1) res+=i1;
            cur.first = ' ';
            cur.second = 0;
            return 0;
        }
    }
}

int main() {
    long long n, m, k;

    string s1, s2;

    cin>>n>>m>>k>>s1>>s2;

    int l1=0, r1=1, l2=0, r2=1;
    while(l1 < n && l2 < m) {
        while(s1[r1]>='0' && s1[r1]<='9' && r1 < n) r1++;
        while(s2[r2]>='0' && s2[r2]<='9' && r2 < m) r2++;

        /*cout<<s1.substr(l1, r1 - l1)<<'\n';
        cout<<s2.substr(l2, r2 - l2)<<'\n';*/
        int mv = comp(s1.substr(l1, r1 - l1), s2.substr(l2, r2 - l2));
        if(mv == 1 && l1 < n) l1 = r1++;
        else if(mv == 2 && l2 < m) l2 = r2++;
        else {
            if(l1 < n) l1 = r1++;
            if(l2 < m) l2 = r2++;
        }
    }
    //cout<<res<<'\n';
    if(res<k) cout<<"Yes";
    else cout<<"No";
    return 0;
}