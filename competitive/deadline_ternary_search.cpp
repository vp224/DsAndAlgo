#include<bits/stdc++.h>
#define fr(i,n) for(int i=0;i<(n);++i)
#define foor(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,n) for(int i=(n);i-->0;)
#define roof(i,b,a) for(int i=(b);i>=(a);--i)
#define elsif else if
#define all(x) x.begin(),x.end()
#define Sort(x) sort(all(x))
#define Reverse(x) reverse(all(x))
#define PQ priority_queue
#define NP(x) next_permutation(all(x))
#define M_PI 3.14159265358979323846
#define popcount __builtin_popcount
using namespace std;            typedef vector<bool> vb; typedef vector<vb>  vvb;
                                typedef vector<int>  vi; typedef vector<vi>  vvi;
typedef long long ll;           typedef vector< ll>  vl; typedef vector<vl>  vvl;
typedef unsigned long long ull; typedef vector<ull>  vu; typedef vector<vu>  vvu;
typedef double dbl;             typedef vector<dbl>  vd; typedef vector<vd>  vvd;
typedef string str;             typedef vector<str>  vs; typedef vector<vs>  vvs;
typedef pair<int,int>pii;       typedef vector<pii>vpii; typedef map<int,int>mii;
typedef pair< ll, ll>pll;       typedef vector<pll>vpll; typedef map< ll, ll>mll;
typedef pair<dbl,dbl>pdd;       typedef vector<pdd>vpdd; typedef map<dbl,dbl>mdd;
typedef pair<str,str>pss;       typedef vector<pss>vpss; typedef map<str,str>mss;
typedef pair<int, ll>pil;       typedef vector<pil>vpil; typedef map<int, ll>mil;
typedef pair< ll,int>pli;       typedef vector<pli>vpli; typedef map< ll,int>mli;
typedef pair<dbl,int>pdi;       typedef vector<pdi>vpdi; typedef map<dbl,int>mdi;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T>set<T>&operator<<(set<T>&s,const T t){s.insert(t);return s;}
template<typename T>stack<T>&operator<<(stack<T>&s,const T t){s.push(t);return s;}
template<typename T>stack<T>&operator>>(stack<T>&s,T&t){t=s.top();s.pop();return s;}
template<typename T>queue<T>&operator<<(queue<T>&q,const T t){q.push(t);return q;}
template<typename T>queue<T>&operator>>(queue<T>&q,T&t){t=q.front();q.pop();return q;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator<<(PQ<T,vector<T>,U>&q,const T t){q.push(t);return q;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator>>(PQ<T,vector<T>,U>&q,T&t){t=q.top();q.pop();return q;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
istream&operator>>(istream&s,_Bit_reference b){int a;s>>a;assert(a==0||a==1);b=a;return s;}
template<typename T>istream&operator>>(istream&s,vector<T>&v){fr(i,v.size()){s>>v[i];}return s;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
//template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<"\n";}return s;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){fr(i,v.size()){i?s<<" "<<v[i]:s<<v[i];}return s;}
template<typename T>ostream&operator<<(ostream&s,const deque<T>d){fr(i,d.size()){i?s<<" "<<d[i]:s<<d[i];}return s;}
template<typename T>_Bit_reference operator&=(_Bit_reference b,T t){return b=b&t;}
template<typename T>_Bit_reference operator^=(_Bit_reference b,T t){return b=b^t;}
template<typename T>_Bit_reference operator|=(_Bit_reference b,T t){return b=b|t;}
template<typename T,typename U>pair<T,U>operator+(pair<T,U>a,pair<T,U>b){return {a.first+b.first,a.second+b.second};}
template<typename T,typename U>pair<T,U>operator-(pair<T,U>a,pair<T,U>b){return {a.first-b.first,a.second-b.second};}
template<typename T,typename U>pair<T,U>&operator+=(pair<T,U>&a,pair<T,U>b){return a=a+b;}
template<typename T,typename U>pair<T,U>&operator-=(pair<T,U>&a,pair<T,U>b){return a=a-b;}
void print(void){cout<<"\n";}
void Print(void){cout<<endl;}
template<typename T>void print(T t){cout<<t<<"\n";}
template<typename T>void Print(T t){cout<<t<<endl;}
template<typename T,typename...U>void print(T&&t,U&&...u){cout<<t<<" ";print(forward<U>(u)...);}
template<typename T,typename...U>void Print(T&&t,U&&...u){cout<<t<<" ";Print(forward<U>(u)...);}
bool YN(bool b){print(b?"YES":"NO");return b;}bool PI(bool b){print(b?"POSSIBLE":"IMPOSSIBLE");return b;}
bool Yn(bool b){print(b?"Yes":"No");return b;}bool Pi(bool b){print(b?"Possible":"Impossible");return b;}
bool yn(bool b){print(b?"yes":"no");return b;}bool pi(bool b){print(b?"possible":"impossible");return b;}
const int e5=1e5;
const int e9=1e9;
const int MD=1e9+7;
const int md=998244353;
const ll e18=1e18;
template<typename T>str to_string(const T&n){ostringstream s;s<<n;return s.str();}
template<typename T>T&chmax(T&a,T b){return a=max(a,b);}
template<typename T>T&chmin(T&a,T b){return a=min(a,b);}
template<typename T,typename U>vector<pair<T,U>>dijkstra(const vector<vector<pair<T,U>>>&E,const U s,const T inf){using P=pair<T,U>;vector<P>d;fr(i,E.size()){d<<P{inf,i};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
template<typename T,typename U>map<U,pair<T,U>>dijkstra(map<U,vector<pair<T,U>>>E,const U s,const T inf){using P=pair<T,U>;map<U,P>d;for(pair<U,vector<P>>e:E){d[e.first]=P{inf,e.first};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
ll maxflow(vector<mil>&E,int s,int t){ll z=0;vi b(E.size(),-1);for(int i=0;;++i){static auto dfs=[&](int v,ll f,auto&dfs)->ll{if(v==t)return f;b[v]=i;for(auto&p:E[v]){if(b[p.first]<i&&p.second){if(ll r=dfs(p.first,min(f,p.second),dfs)){p.second-=r;E[p.first][v]+=r;return r;}}}return 0;};ll x=dfs(s,ll(1e18),dfs);z+=x;if(x==0)return z;}}
template<typename T>T distsq(pair<T,T>a,pair<T,T>b){return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);}
template<typename T>T max(const vector<T>a){assert(a.size());T m=a[0];for(T e:a){m=max(m,e);}return m;}
template<typename T>T min(const vector<T>a){assert(a.size());T m=a[0];for(T e:a){m=min(m,e);}return m;}
template<typename T>T gcd(const T a,const T b){return a?gcd(b%a,a):b;}
template<typename T>T gcd(const vector<T>a){T g=a[0];for(T e:a){g=gcd(g,e);}return g;}
template<typename T>vector<T>LCS(vector<T>A,vector<T>B){int N=A.size(),M=B.size();vector<vector<pair<int,pii>>>d(N+1,vector<pair<int,pii>>(M+1));fr(i,N){fr(j,M){if(A[i]==B[j]){d[i+1][j+1]={d[i][j].first+1,{i,j}};}else{d[i+1][j+1]=max(d[i][j+1],d[i+1][j]);}}}vector<T>r;for(pii p={N,M};d[p.first][p.second].first;p=d[p.first][p.second].second){r<<A[d[p.first][p.second].second.first];}Reverse(r);return r;}
str LCS(str S,str T){vector<char>s=LCS(vector<char>(S.begin(),S.end()),vector<char>(T.begin(),T.end()));return str(s.begin(),s.end());}
template<typename T>vector<pair<T,T>>ConvexHull(vector<pair<T,T>>V){if(V.size()<=3){return V;}Sort(V);rf(i,V.size()-1)V<<V[i];vector<pair<T,T>>r;for(pair<T,T>p:V){int s=r.size();while(s>=2&&(p.second-r[s-1].second)*(p.first-r[s-2].first)<(p.second-r[s-2].second)*(p.first-r[s-1].first)){r.pop_back();--s;}r<<p;}r.pop_back();return r;}
class UnionFind{vi p,s;void extend(int N){foor(i,p.size(),N){p<<i;s<<1;}}public:UnionFind(void){}UnionFind(int N){extend(N-1);}int find(int i){extend(i);return p[i]=p[i]==i?i:find(p[i]);}void unite(int a,int b){extend(a);extend(b);if((a=find(a))!=(b=find(b))){if(s[a]>s[b]){swap(a,b);}s[b]+=s[a];p[a]=b;}}void unite(pii p){return unite(p.first,p.second);}bool same(int a,int b){extend(a);extend(b);return find(a)==find(b);}bool same(pii p){return same(p.first,p.second);}int size(int x){extend(x);return s[find(x)];}};
ll MST(vector<pair<ll,pii>>&E){Sort(E);UnionFind uf;ll z=0;for(auto&e:E){if(!uf.same(e.second)){z+=e.first;uf.unite(e.second);}}return z;}
ll strmod(const str&s,const int m){ll x=0;fr(i,s.size()){x=(x*10+s[i]-48)%m;}return x;}
vvl mul(const vvl&A,const vvl&B,const int m){vvl C;fr(y,A.size()){C<<vl(B[y].size());}fr(y,C.size()){fr(x,C[y].size()){fr(i,A[0].size()){(C[y][x]+=A[y][i]*B[i][x])%=m;}}}return C;}
vvl pow(const vvl&A,const ll n,const int m){vvl B;fr(y,A.size()){B<<vl(A.size());}if(n==0){fr(i,B.size()){B[i][i]=1;}}elsif(n%2){B=mul(A,pow(A,n-1,m),m);}else{vvl C=pow(A,n/2,m);B=mul(C,C,m);}return B;}
ll pow(const ll a,const ll n,const int m){ll t;return n?(n&1?a>=0?a%m:(m-(-a%m))%m:1)*(t=pow(a,n>>1,m),t*t%m)%m:!!a;}
ll inv(const ll x,const int p){assert(x!=0);return pow(x,p-2,p);}
ll inv(const ll x){return inv(x,MD);}
vpll fact(const int n,const int p){assert(n<p);vpll v(n+1);v[0].first=1;foor(i,1,n){v[i].first=v[i-1].first*i%p;}v[n].second=inv(v[n].first,p);roof(i,n,1){v[i-1].second=v[i].second*i%p;}return v;}
class Combination{const vpll f;const int M;public:Combination(int n,int m):f(fact(n,m)),M(m){}Combination(int n):Combination(n,MD){}ll P(int n,int k){return n<0||k<0||n<k?0ll:f[n].first*f[n-k].second%M;}ll C(int n,int k){return k<0?0:P(n,k)*f[k].second%M;}ll H(int n,int k){return n==0&&k==0?1ll:C(n+k-1,k);}ll F(int n){return n<0?0:f[n].first;}};
ll C2(const int n){return(ll)n*~-n/2;}
ll sum(const vi a){ll s=0;for(int e:a){s+=e;}return s;}
ll sum(const vl a){ll s=0;for(ll e:a){s+=e;}return s;}
template<typename T>int MSB(T N){int r=-1;for(;N>0;N/=2){++r;}return r;}
template<typename T>class SegmentTree{vector<T>S;T(*const op)(T a,T b);const T zero;const int B;public:SegmentTree(int N,T(*f)(T a,T b),const T zero):S(1<<MSB(N-1)+2,zero),op(f),zero(zero),B(1<<MSB(N-1)+1){}SegmentTree(vector<T>v,T(*f)(T a,T b),const T zero):SegmentTree(v.size(),f,zero){fr(i,v.size()){S[S.size()/2+i]=v[i];}roof(i,S.size()/2-1,1){S[i]=op(S[i*2],S[i*2+1]);}}T calc(int l,int r){l+=B;r+=B;if(l>r){return zero;}if(l==r){return S[l];}T L=S[l],R=S[r];for(;l/2<r/2;l/=2,r/=2){if(l%2==0){L=op(L,S[l+1]);}if(r%2==1){R=op(S[r-1],R);}}return op(L,R);}void replace(int i,T x){for(S[i+=B]=x;i!=1;i/=2){if(i%2){S[i/2]=op(S[i-1],S[i]);}else{S[i/2]=op(S[i],S[i+1]);}}}void add(int i,T x){replace(i,op(S[B+i],x));}T top(){return S[1];}T get(int i){return S[i+B];}};
ll BITsum(vl&B,int i){ll z=0;while(i>0){z+=B[i];i-=i&-i;}return z;}
void BITadd(vl&B,int i,ll x){while(i<B.size()){B[i]+=x;i+=i&-i;}}
ll fib(const ll n,const int m){ll a,b,c,d,A,B,C,D;a=1;b=0;c=0;d=1;rf(i,63){A=a*a+b*c;B=a*b+b*d;C=c*a+d*c;D=c*b+d*d;if(n>>i&1){a=A;b=B;c=C;d=D;A=a+b;B=a;C=c+d;D=c;}a=A%m;b=B%m;c=C%m;d=D%m;}return b;}
vi primes(int n){vb b(n+1);vi p;foor(i,2,n){if(!b[i]){p<<i;for(int j=2*i;j<=n;j+=i){b[j]=true;}}}return p;}
vb isprime(const int n){vb v(n+1,true);v[0]=v[1]=false;foor(i,2,n){if(v[i]){for(int j=2*i;j<=n;j+=i){v[j]=false;}}}return v;}
class LCA{vvi par;vi dep;public:LCA(vvi&E,int root):par(MSB(E.size())+1,vi(E.size())),dep(E.size()){function<void(int,int)>dfs=[&](int i,int p){for(int j:E[i])if(j!=p){par[0][j]=i;dep[j]=dep[i]+1;dfs(j,i);}};par[0][root]=root;dfs(root,root);fr(i,par.size()-1){fr(j,par[0].size()){par[i+1][j]=par[i][par[i][j]];}}}int operator()(int a,int b){if(dep[a]>dep[b])swap(a,b);for(int t=dep[b]-dep[a],i=0;t;t>>=1,++i){if(t&1){b=par[i][b];}}if(a==b)return a;rf(i,par.size()){if(par[i][a]!=par[i][b]){a=par[i][a];b=par[i][b];}}return par[0][a];}};
vpli factor(ll N){vpli r;for(ll i=2;i*i<=N;++i){if(N%i==0){r<<pli{i,0};while(N%i==0){N/=i;++r.back().second;}}}if(N>1){r<<pli{N,1};}return r;}
vl divisors(ll n){vl r;ll m=sqrt(n);foor(i,1,m)if(n%i==0)r<<ll(i);rf(i,r.size()-(m*m==n))r<<n/r[i];return r;}
vi SuffixArray(str S){int N=S.size();vi rank(N+1),tmp(N+1),sa(N+1);fr(i,N){sa[i]=i;rank[i]=S[i];}sa[N]=N;rank[N]=-1;int k;auto cmp=[&](int&a,int&b)->bool{if(rank[a]!=rank[b])return rank[a]<rank[b];return (a+k<=N?rank[a+k]:-1)<(b+k<=N?rank[b+k]:-1);};for(k=1;k<=N;k*=2){sort(all(sa),cmp);tmp[sa[0]]=0;foor(i,1,N){tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);}rank=tmp;}return sa;};
 
int main(){cin.tie(0);ios::sync_with_stdio(false);
    int Q;cin>>Q;
    fr(_,Q){
        int N,D;cin>>N>>D;
        function<int(int)>f=[&](int x){return x+~-D/-~x+1;};
        int L=0,R=N;
        fr(_,200){
            int l=(2*L+R)/3,r=(L+2*R)/3;
            if(f(l)<f(r)){
                R=r;
            }else{
                L=l;
            }
        }
        bool b=false;
        foor(x,max(0,L-e5),R+e5){
            b|=f(x)<=N;
        }
        YN(b);
    }
    return 0;
}