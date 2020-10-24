#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int n;
    int m;
    int x;
    int y;
    while(t--) {
        cin>>n;
        cin>>m;
        cin>>x;
        cin>>y;
        int a[100][1000];
        string s;
        for(int i=0;i<n;i++) {
            cin>>s;
            for(int j=0;j<m;j++) {
                if(s[j] == '*')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        }
        vector<vector<int> > range;
        for(int i=0;i<n;i++) {
            vector<int> temp;
            temp.clear();
            int count=0;
            for(int j=0;j<m;j++) {
                if(a[i][j]==0) {
                    count++;
                }
                else {
                    temp.push_back(count);
                    count = 0;
                }
            }
            if(count!=0){
                temp.push_back(count);
            }
            range.push_back(temp);
        }
        int fin =0;
        for(int i=0;i<range.size();i++) {
            for(int j=0;j<range[i].size();j++) {
//                cout<<range[i][j]<<" ";
                if(range[i][j]%2==0) {
                    fin+= min(y*(range[i][j]/2),range[i][j]*x);
                }
                else {
                    if(range[i][j]>1) {
                        fin+=min(y*((range[i][j]-1)/2)+x,x*range[i][j]);
                    }
                    else if(range[i][j]==1){
                        fin+=x;
                    }
                }
            }
        }
        cout<<fin<<'\n';
    }
}