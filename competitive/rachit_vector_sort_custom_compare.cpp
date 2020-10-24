#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
    return (x%10) > (y%10); 
}
int main() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    int ans = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        ans += arr[i]/10;
    }
    sort(arr, arr+n, cmp);
    int i = 0;
    while(i<n && k>0){
        if(arr[i]==100) break;
        int a = arr[i]%10;
        if(k>=(10-a)){
            k-=(10-a);
            arr[i] += 10-a;
            i++;
            ans++;
        }
        else{
            break;
        }
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        int a = 100 - arr[i];
        if(k==0) break;
        if(k>=a){
            ans += a/10;
            k -= a;
        }
        else{
            ans += k/10;
            break;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}