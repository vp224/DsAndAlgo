#include "bits/stdc++.h"
using namespace std;

int main(){
	int t,n,prev,i;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n);
		cin>>a[0];
		prev=a[0];
		for(i=1;i<n;i++){
			cin>>a[i];
			if((a[i]-prev)%2 !=0){
				cout<<"NO"<<'\n';
				break;
			}
			else{
				prev=a[i];
			}         
		}
		if(i == n)
			cout<<"YES"<<'\n';
	}
}