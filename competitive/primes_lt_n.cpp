/* primes less than n using seieve maybe 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> primes(int n)
{
    vector<bool> b(n+1);
    vector<int> p;
    for(int i=2;i<=n;++i){
        if(!b[i]){
            p.push_back(i);
            for(int j=2*i;j<=n;j+=i)
            {
                b[j]=true;
            }
        }
    }
    return p;
}

int main() {
    int n;
    cin>>n;
    vector<int> primesvec;
    primesvec = primes(n);
    vector<int> diff;
    for(int i=1;i<primesvec.size();i++) {
        diff.push_back(primesvec[i]-primesvec[i-1]);
    }
    for(int i=0;i<diff.size();i++){
        cout<<diff[i]<<" ";
    }
    cout<<'\n';
}