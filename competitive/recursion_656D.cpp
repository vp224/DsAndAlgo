#include<bits/stdc++.h>
using namespace std;

string s;
int n;
string target;
string arr[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
string man(int temp) {
    string ans;
    ans = arr[temp - 1] + arr[temp];
    return ans;
}

int temp(char x,int l, int r) {
    int ans =0;
    for(int i=l;i<=r;i++) {
        if(s[i]!=x) {
            ans++;
        }
    }
    return ans;
}
int solve(char x, int low,int high,int otherlow,int otherhigh) {// low to high should have x and other half should half should have the rest
    if(x==target[1]){
        if(low>high) {
            return s[low-1]==x?0:1;
        }
        return s[low]==x?0:1;

    }

    int t1 = temp(x,low,high);
    int t2 = solve(x+1,otherlow,(otherlow+otherhigh)/2,((otherlow+otherhigh)/2)+1,otherhigh);
    int t3 = solve(x+1,((otherlow+otherhigh)/2)+1 ,otherhigh,otherlow,(otherlow+otherhigh)/2);
    return t1 + min(t2,t3);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;

        cin>>s;
        if(n==1 ){
            if(s[0]!='a') {
                cout<<1<<"\n";
                continue;
            }
            else {
                cout<<0<<"\n";
                continue;
            }
        }
        int tmp = log2(n);
        target = man(tmp);
        int low = 0;
        int high = n-1;
        int mid = (low+high)/2;
        int t1 = solve('a',low,mid,mid+1,high);
        int t2 = solve('a',mid+1,high,low,mid);
        int ans = min(t1,t2);
        cout<<ans<<"\n";
    }
}