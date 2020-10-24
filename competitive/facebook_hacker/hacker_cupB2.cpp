#include<bits/stdc++.h>
#define inp 200005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }
using namespace std;

int n;
string s;
int main() {
    jaldi

    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        cin>>n;
        cin>>s;
        int o=0,e=0;
        for(int i=0;i<n;i++) {
            s[i]=='A'?(o++):(e++);
        }
        char ans=(abs(o-e)==1)?'Y':'N';
        cout<<"Case #"<<z<<": "<<ans<<'\n';
    }
}
