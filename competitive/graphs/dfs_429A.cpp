#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N = 1e5+7;
vector<int> adj[N];
vector<int> init(N);
vector<int> goal(N);
vector<int> ans;
void dfs(int root, int par, vector<int>& level) {
    for(int i=0;i<adj[root].size();i++) {
        if(adj[root][i]==par) continue;
        level[adj[root][i]] = level[root]+1;
        dfs(adj[root][i], root, level);
    }
}

void dfs1(int root, int par, int evencount, int oddcount, vector<int>& level) {

    if(level[root]%2==0) { //evenlevel , so use evencount
        int val = (evencount%2)? (!init[root]):(init[root]);
        if(val!=goal[root]) {
            evencount++;
            ans.push_back(root);
            init[root]=goal[root];
        }
    }
    else {
        int val = (oddcount%2)? (!init[root]):(init[root]);
        if(val!=goal[root]) {
            oddcount++;
            ans.push_back(root);
            init[root]=goal[root];
        }
    }

    for(int i=0;i<adj[root].size();i++) {
        if(adj[root][i]!=par) {
            dfs1(adj[root][i], root, evencount, oddcount, level);
        }
    }
}
int main() {

    jaldi

    int n;
    cin>>n;
    int edge = n-1;
    int x;
    int y;
    vector<int> level(n+1);
    while(edge--) {
        cin>>x;
        cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        cin>>init[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>goal[i];
    }
    level[1]=1;
    dfs(1,0,level);

//    for(int i=1;i<=n;i++) {
//        cout<<i<<":"<<level[i]<<"\n";
//    }
//    cout<<'\n';
    dfs1(1,0,0,0,level);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<'\n';
    }
}
