#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void dfs(int n, int m , int& ans) {
    if(n==m){
        return;
    }
    else if(n>m){
        ans+=(n-m);
        return ;
    }
    else {
        if(m%2==0){
            ans++;
            dfs(n,m/2,ans);
        }
        else {
            ans++;
            dfs(n,m+1,ans);
        }

    }
}
int main() {

    jaldi

    int n;
    cin>>n;
    int m;
    cin>>m;
    int ans =0;
    dfs(n,m,ans);
    cout<<ans<<'\n';
}
