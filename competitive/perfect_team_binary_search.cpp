#include<bits/stdc++.h>
using namespace std;
int check(int c, int m,int group) {
    if(min(c,m)>=group) {
        return 1;
    }
    return 0;
}
int main() {
    int t;
    cin>>t;
    int c;
    int m;
    int x;
    while(t--) {
        cin>>c;
        cin>>m;
        cin>>x;
        int sum = c+m+x;
        int l=0;
        int r=floor(sum/3);
        int ans=0;
        while(l<=r) {
            int mid = (l+r)/2;
            if(check(c,m,mid)) {
                l=mid+1;
                ans = l;
            }
            else {
                r=mid-1;
            }
        }
        cout<<ans-1<<'\n';
    }
}