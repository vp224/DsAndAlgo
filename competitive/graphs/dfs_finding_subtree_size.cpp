#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void dfs(vector<int> &sz, vector<int> adj[], int root, int par) {
    sz[root]=1;
    for(int i=0;i<adj[root].size();i++) {
        if(adj[root][i]!=par) {
            dfs(sz,adj,adj[root][i], root);
            sz[root]+=sz[adj[root][i]];
        }
    }
}
int main() {

    jaldi

    int n;
    cin>>n;
    vector<int> adj[10];
    vector<int> sz(10);
    int x;
    int y;
    for(int i=0;i<9;i++) {
        cin>>x;
        cin>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(sz,adj, 0, -1);
    for(int i=0;i<10;i++) {
        cout<<sz[i]<<" ";
    }
}
