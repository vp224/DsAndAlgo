#include <bits/stdc++.h>
using namespace std;

void pushedge(vector<int> a[], int u, int v) {
    a[u].push_back(v);
    a[v].push_back(u);
}

void printGraph(vector<int> a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++) {
        cout<<i<<"-> "<<a[i][j]<<'\n';
        }
    }
    
}

void bfs( vector<int> a[], int n , int v){
    
    
    vector<int> visited(n);
    queue<int> q;
    q.push(v);
    visited[v]=1;
    while(!q.empty()) {
        int front = q.front();
        cout<< front << " ";
        q.pop();
        for(int i=0;i<a[front].size();i++) {
            if(visited[a[front][i]]!=1) {
                q.push(a[front][i]);
                visited[a[front][i]] = 1;
            }
        }
    }
    
}
int main() {
// 	cout<<"GfG!";
	long long int n,w,h;
	cin>>n;
	vector<int> adj[n];
	pushedge(adj, 0, 1); 
    pushedge(adj, 0, 4); 
    pushedge(adj, 1, 2); 
    pushedge(adj, 1, 3); 
    pushedge(adj, 1, 4); 
    pushedge(adj, 2, 3); 
    pushedge(adj, 3, 4); 
	    /* code */
    bfs(adj,n,0);
	return 0;
}