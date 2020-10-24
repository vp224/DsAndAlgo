#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    int firstpos=-1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        if(a[i]>0) {
            firstpos=i;
            break;
        }
    }
    if(firstpos==-1) {
        cout<<0<<'\n';
        return 0;
    }
    int max_here = 0;
    int l=firstpos;
    int r=firstpos;
    int max_sum = INT_MIN;
    pair<int, int> pos;
    while(l<=r && r<n) {
     max_here = max_here+a[r];
     if(max_sum < max_here) {
         pos.first = l;
         pos.second = r;
         max_sum = max_here;
     }
     if(max_here<0) {
         max_here=0;
         l=r+1;
         r=l;
     }
     else {
         r++;
     }
    }
    int max_range = INT_MIN;
    for(int i=pos.first;i<=pos.second;i++) {
        max_range = max(max_range, a[i]);
    }

    cout<<max_sum<<'\n';
    cout<<pos.first<<" "<<pos.second<<'\n';
}
