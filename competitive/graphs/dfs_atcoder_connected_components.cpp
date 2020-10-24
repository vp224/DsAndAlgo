#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
vector<int> ans[N];
vector<int> visited(N+1);
int k=0;
void DFSUtil(int v)
{
    visited[v] = true;
//    cout << k<<" "<<v << " ";
    ans[k].push_back(v);
    for(int i = 0; i < adj[v].size(); ++i)
        if(!visited[adj[v][i]])
            DFSUtil(adj[v][i]);
}

void connectedComponents(vector<int> arr[], int V)
{
    // Mark all the vertices as not visited
    for(int v = 1; v <= V; v++)
        visited[v] = false;

    for (int v=1; v<=V; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v);
            k++;
//            cout << "\n";
        }
    }
}



// method to add an undirected edge
void addEdge(int v, int w)
{

}

int main() {
    int n;
    int m;
    cin>>n;
    cin>>m;
    int x;
    int y;

    while(m--) {
        cin>>x;
        cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    connectedComponents(ans,n);
    int maxi = INT_MIN;
    for(int i=0;i<N;i++) {
        if(ans[i].size()!=0) {
            int k = ans[i].size();
            if(k>maxi) {
                maxi = k;
            }
        }
    }
    cout<<maxi<<'\n';
}