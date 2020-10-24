#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define NREP(i,a,b) for(int i=a;i>=b;i--)
#define clr(a) memset(a,0,sizeof a)
#define CLR(a,t) memset(a,t,sizeof a)
#define help ios::sync_with_stdio(0)
#define SORTV(a,n) sort(a.begin(),a.begin()+n)
#define SORTA(a,n) sort(a,a+n)
#define f first
#define ii second
#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef long double ld;
#define vip vector<pair<ll,ll>>
#define vv vector<vector<ll>>
#define vi vector<ll>
#define FORS(it,m) for(set<int>::iterator it=m.begin();it!=m.end();it++)
#define FORM(it,m) for(map<ll,ll>::iterator it=m.begin();it!=m.end();it++)
#define FORV(it,m) for(vector<ll>::iterator it=m.begin();it!=m.end();it++)
#define FORL(it,l) for(list<int> :: iterator it=l.begin();it!=l.end();it++)
#define MAX6 1000000
#define MAX5 100000
#define MAX4 10000
#define ipair pair<int,int>
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define minHeap priority_queue<ipair,vector<ipair>,greater<ipair>>
#define maxHeap priority_queue<ipair>
#define iMap map<ipair,ll>
#define piMap map<pair<ll,ll>,ll>
#define MOD 998244353
#define iMax INT_MAX
#define llMax LONG_MAX
#define sz(a) a.size()
#define tc(t) ll t; cin>>t; while(t--)
#define debArr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";  cout<<endl;
bool persqr(int a) { return (int(sqrt(a))*int(sqrt(a))==a)?1:0; }
int gcd(int a,int b) { return (a?gcd(b%a,a):b);}
bool powerOf2(int a)   {   return !(a&(a-1));}
ll abs(ll n1,ll n2){    return n1>n2?n1-n2:n2-n1;}
ll highestPowerof2(ll n) { return pow(2,(ll)log2(n)); }

ll ans,n,m,c[2*MAX6],mem[2*MAX6];

ll dp(ll ind,ll cost){
    if(ind+m>=n-1){
        ans=min(ans,cost);
        return cost;
    }
    if(mem[ind]==llMax) return llMax;
    if(mem[ind]!=-1){
        ans=min(ans,cost+mem[ind]);
        return cost+mem[ind];
    }

    ll p=llMax;
    REP(i,ind+1,ind+m+1) if(c[i]!=0)   p=min(p,dp(i,cost+c[i]));

    if(p!=llMax)    mem[ind]=p-cost;
    else mem[ind]=p;
    return p;
}

int main(){
    help;
    ll t; cin>>t;
    for(int i = 1;i<=t;i++){
        CLR(mem,-1);
        ans=llMax;
        cin>>n>>m;
        if(m>=n-1)    ans=0;
        REP(i,0,n)  cin>>c[i];
        REP(i,0,m+1)    if(c[i]!=0) dp(i,c[i]);
        if(ans==llMax)    ans=-1;
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}