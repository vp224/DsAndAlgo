#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n , k ;
    cin >> n  >> k ;
    if ( k > n ) {
        cout << n+k ;
        return 0 ;
    }
    else {
        for ( int i = k-1 ; i >= 0 ; i--) {
            if ( n % i == 0 ) {
        long long a = n/i  ;
        long long b = k * a ;
                cout << b + i ;
                return 0 ;
            }
        }
    }
}