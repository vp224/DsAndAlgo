#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int n;
    for(int cas=1;cas<=t;cas++) {
        cin>>n;
        int cnta=0;
        int cntb=0;
        string s;
        cin>>s;
        for(int i=0;i<n;i++) {
            if(s[i]=='A') {
                cnta++;
            }
            else {
                cntb++;
            }
        }
        if(abs(cnta-cntb)==1) {
            cout<<"Case #"<<cas<<":"<<" "<<'Y'<<'\n';
        }
        else {
            cout<<"Case #"<<cas<<":"<<" "<<'N'<<'\n';
        }
    }
}
