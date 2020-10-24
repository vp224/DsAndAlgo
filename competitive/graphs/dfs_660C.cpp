#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const long long int N = 1e5+7;
vector<long long int> adj[N];
vector<long long int> p(N);
void dfs ( long long int root, long long int e , vector<long long int>& count1) {
    count1[root] = p[root];

    for(long long int i=0;i<adj[root].size();i++) {
        if (adj[root][i] == e)
            continue;
        dfs(adj[root][i],root,count1);
        count1[root] += count1[adj[root][i]];
    }
}

bool isposs = 1;

void check1(long long int root,long long int e, vector<long long int>& unhappy, vector<long long int>& count1) {
    long long int badchild =0;
    for(int i=0;i<adj[root].size();i++) {
        if(adj[root][i]==e)
            continue;
        check1(adj[root][i],root,unhappy,count1);
        badchild += unhappy[adj[root][i]];
    }

    cout<<"Badchild for"<<root<<"is :"<<badchild<<'\n';
    if(unhappy[root] > p[root]+badchild) {
        isposs=0;
    }
}


void check(vector<long long int>& happy,vector<long long int>& count1, bool& flag, int n) {
    for(int i=1;i<=n;i++) {
        if (happy[i] >= (-1 * count1[i]) && happy[i] <= count1[i]) {
            if ((count1[i] + happy[i]) % 2 == 0) {
                flag = true;
            } else {
                flag = false;
                return;
            }
        } else {
            flag = false;
            return;
        }
    }
}

void dfs2(long long int root, long long int e, vector<long long int>& mainunhappy, vector<long long int>& unhappy) {
    mainunhappy[root] = unhappy[root];
    for(long long int i=0;i<adj[root].size();i++) {
        if (adj[root][i] == e)
            continue;
        dfs2(adj[root][i],root,mainunhappy,unhappy);
        mainunhappy[root] += mainunhappy[adj[root][i]];
    }
}


int main() {

    jaldi

    long long int t;
    cin>>t;
    long long int n;
    long long int m;
    while(t--) {
        cin>>n;
        cin>>m;
        isposs=1;
        for(long long int i=0;i<N;i++){
            adj[i].clear();
        }
        p.clear();
        vector<long long int> count1(n+1,0);
        for(long long int i=1;i<=n;i++) {
            cin>>p[i];
        }

        vector<long long int> happy(n+1);
        vector<long long int> unhappy(n+1);
        for(long long int i=1;i<=n;i++) {
            cin>>happy[i];
        }

        long long int edge = (n-1);
        long long int x;
        long long int y;
        while(edge--) {
            cin>>x;
            cin>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,0,count1);
//        for(long long int i=0;i<count1.size();i++) {
//            if(count1[i]) {
//                cout<<"Vertex"<<i<<" : "<<count1[i]<<'\n';
//            }
//        }
        //completed with the number of people traversing this city.
        bool flag=true;
        check(happy,count1,flag,n);
        if(flag) {
            for(long long int i=1;i<=n;i++) {
                unhappy[i] = (count1[i]-happy[i])/2;
            }

            bool flag1 = true;
//            vector<long long int> mainunhappy(n+1,0);
//            dfs2(1,0,mainunhappy,unhappy);
//            for(long long int i=0;i<mainunhappy.size();i++) {
//                mainunhappy[i]-=unhappy[i];
//            }

            check1(1,0,unhappy,count1);
            if(isposs){
                cout<<"YES"<<'\n';
            }
            else {
                cout<<"NO"<<'\n';
            }
        }
        else {
            cout<<"NO"<<'\n';
        }
    }
}