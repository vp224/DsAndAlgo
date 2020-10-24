#include<bits/stdc++.h>
using namespace std;
int powers[10] ={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main() {
	int n;
	cin>>n;
	for(int m=1;m<=3;m++) {
	for(int r=1;r<=3;r++) {
	for(int l=1;l<=3;l++){
	for(int z=1;z<=3;z++) {
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				for(int k=1;k<=3;k++) {
					cout<<m*powers[6]+r*powers[5]+l*powers[4]+z*powers[3]+i*powers[2]+j*powers[1]+k*powers[0];
					cout<<'\n';
				}
			}

		}
	}
}
}
}
}