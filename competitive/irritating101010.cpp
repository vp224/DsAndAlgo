#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	string s;
	while(t--) {
		cin>>s;
		//type1
		int n=s.length();
		int mintyp1 = INT_MAX;
		for(int p = 1;p<=n;p++) {
			int edit =0;
			for(int i=0;i<p;i++) {
				if(s[i]!='0') {
					edit++;
				}
			}
			for(int i=p;i<n;i++) {
				if(s[i]!='1') {
					edit++;
				}
			}
			mintyp1 = min(mintyp1,edit);
		}

		int mintyp2 = INT_MAX;
		for(int p = 1;p<=n;p++) {
			int edit =0;
			for(int i=0;i<p;i++) {
				if(s[i]!='1') {
					edit++;
				}
			}
			for(int i=p;i<n;i++) {
				if(s[i]!='0') {
					edit++;
				}
			}
			mintyp2 = min(mintyp2,edit);
		}

		cout<<min(mintyp2,mintyp1)<<'\n';
	}
}