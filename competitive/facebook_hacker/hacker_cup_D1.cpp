#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int> >, greater<pair<long long int,long long int> > > pqSize;
int main() {
    jaldi

    long long int t;
    cin>>t;
    long long int n;
    long long int m;
    for(long long int z = 1;z<=t;z++) {
        cin>>n;
        cin>>m;
        long long int cap = m;
        vector<long long int> c(n);
        for(long long int i=0;i<n;i++) {
            cin>>c[i];
        }
        pqSize pq;
        long long int ans =0;
        bool isposs = true;
        pair<long long int,long long int> prev;
        for(long long int i=0;i<n;) {
            if(m==0 && i==(n-1)) {
                break;
            }
            if(m>0) {
                if(c[i]!=0) {
                    pq.push(make_pair(c[i], i));
                    prev.first = c[i];
                    prev.second = i;
                }
                m--;
                i++;
            }
            else if(m==0){
                if(c[i]!=0) {
                    m+=cap;
                    ans+=c[i];
                    i++;
                    m--;
                }
                else {
                    if (pq.empty()) {
                        cout <<"Case #"<<z<<": "<< -1 << '\n';
                        isposs = false;
                        break;
                    }
                        m = cap - (i - pq.top().second);
                        if (m > 0) {
                            ans += pq.top().first;
                            pq.pop();
                        } else {
                            m = cap - (i - prev.second);
                            ans += prev.first;
                            if(m==1 && c[i+1]==0) {
                                isposs=false;
                                cout <<"Case #"<<z<<": "<< -1 << '\n';
                                break;
                            }
                        }
                    i++;
                    m--;
                }
            }
        }
        if(isposs) {
            cout <<"Case #"<<z<<": "<< ans << '\n';
        }
    }
}
