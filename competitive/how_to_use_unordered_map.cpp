#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n;
    cin>>m;
    unordered_map<int, bool> has;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        has[x] = true;
    }
    int tot = 0;
    vector<int> ans;
    for(int i=1; ; ++i) {
        if(tot + i > m) break;
        if(!has.count(i)) { // to check if i is present in the map or not , .count returns the number of keys present in the map with key = i; 
            tot += i;
            ans.push_back(i);
        }
    }
    printf("%u\n", ans.size());
    for(auto & it : ans) printf("%d ", it);

    return 0;
}