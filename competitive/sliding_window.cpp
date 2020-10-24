#include<bits/stdc++.h>
using namespace std;
 
int toggle(vector<int> a) {
    for(int i=0;i<3;i++) {
        if(a[i]==0) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        vector<int> freq(3,0);
        for(int i=0;i<s.size();i++) {
            if(s[i]=='1') {
                freq[0]++;
            }
            else if(s[i]=='2') {
                freq[1]++;
            }
            else {
                freq[2]++;
            }
        }
        bool isposs= true;
        for(int i=0;i<3;i++) {
            if(freq[i]==0) {
                cout<<0<<'\n';
                isposs=false;
                break;
            }
        }
        if(!isposs) {
            continue;
        }
        else {
            vector<int> ispres(3,0);
            int start =0;
            int end = 0;
            int minlen = INT_MAX;
            int prevstart = 0;
            while(start<=end && end<s.size()) {
                if(prevstart==start) {
                    ispres[s[end] - '1']++;
                }
                int res = toggle(ispres);
                if(res == 1) {
                    end++;
                    prevstart=start;
                }
                else {
                    minlen = min(minlen, end-start+1);
                    if(minlen==3)
                        break;
                    prevstart = start;
                    start++;
                    ispres[s[start-1]-'1']--;
 
                }
            }
            cout<<minlen<<'\n';
        }
    }
}