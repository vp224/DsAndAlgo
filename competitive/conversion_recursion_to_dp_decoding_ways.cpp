#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ston(string s) {
    int val = 0;
    int n = s.length();
    for(int i=0;i<n;i++) {
        val+=(s[i]-'0')*pow(10,(n-i)-1);
    }
    return val;
}
unordered_map<string, int> um;
int numDecodings(string s) {
    int n= s.length();
    if(s[0]=='0') {
        um[s] =0;
        return 0;
    }
    else if(n==1) {
        um[s]=1;
        return 1;
    }
    else if(n==2) {
        int temp1 = ston(s.substr(0,2));
        if(s=="10") {um[s]=1;return 1;}
        else if(s=="20") {um[s]=1;return 1;}
        else if(temp1<=26) {um[s]=2;return 2;}
        else if(s[0]=='0'||s[1]=='0') {um[s]=0;return 0;}
        else {um[s]=1;return 1;}
    }

    if(um.find(s)!=um.end()) {
        return um[s];
    }
    int temp = ston(s.substr(0,2));
    string s1 = s.substr(1, n-1);
    string s2 = s.substr(2,(n-2));
    if(temp<=26) {
        int x = numDecodings(s1)+numDecodings(s2);
        um[s]=x;
        return x;
    }
    else {
        int y= numDecodings(s1);
        um[s]=y;
        return y;
    }
}
int main() {

    jaldi

    string s;
    cin>>s;
    int ans = numDecodings(s);

    cout<<um[s]<<'\n';
}
