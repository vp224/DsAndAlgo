#include <bits/stdc++.h>
using namespace std;

int main() {
// 	cout<<"GfG!";
	int t;
	int n,k;
	cin>>t;
	while(t--) {
	    cin>>n;
	    cin>>k;
	    vector<int> a(n);
        vector<int> ans;
        ans.clear();
        bool gone = false;
	    int target = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(i<k){
                target+=a[i];
            }
        }
        cout<<"target:"<<target<<'\n';
        for(int i=0;i<k;i++) {
            ans.push_back(a[i]);
        }
        int pushed = a[0];
        for(int i=0;i<(n-k);i++) { 
            // ans.push_back(a[i]);
            if(a[k+i] == pushed) {ans.push_back(a[k+i]);}
            else if(a[k+i] == a[k+i-1]) {
                ans.push_back(a[i]);
            }
            else {
                cout<<-1<<"\n";gone=true;
                break;
            }
        
        }
        if(gone) continue;
        int sum =0;
        for(int i= (n-k);i<n;i++) {
            sum+=a[i];
        }
        if(sum==target){
            for(int i = n-k;i<n;i++){
            ans.push_back(a[i]);
            }
        }
        else if(sum < target) {
            for(int i = n-k;i<n;i++){
            ans.push_back(a[i]);
            }
            ans.push_back(target-sum);
        }
        else{
            cout<<"-1"<<'\n';
            continue;
        }
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
	}
	    /* code */
    
	return 0;
}