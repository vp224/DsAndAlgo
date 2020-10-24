#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[50];
bool isReachable(int s, int d)
{
    if (s == d)
        return true;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for (int j = 0;j<adj[s].size();j++)
        {
            if (adj[s][j] == d)
                return true;

            if (!visited[adj[s][j]])
            {
                visited[adj[s][j]] = true;
                queue.push_back(adj[s][j]);
            }
        }
    }

    return false;
}
int main() {
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
        cin>>n;
        string in;
        cin>>in;
        string out;
        cin>>out;
        int x = 0;
        int y = 1;
        for(int i=0;i<50;i++) {
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++) {
            if(in[y]=='Y' && out[x]=='Y') { // x->y
                adj[x].push_back(y);
            }
            if(in[x]=='Y' && out[y]=='Y') { //y->x
                adj[y].push_back(x);
            }
            x++;
            y++;
        }
        //adjacency matrix constructed
        cout<<"Case #"<<cas<<":"<<'\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(isReachable(i,j)) {
                    cout<<"Y";
                }
                else {
                    cout<<"N";
                }
            }
            cout<<'\n';
        }
    }
}
