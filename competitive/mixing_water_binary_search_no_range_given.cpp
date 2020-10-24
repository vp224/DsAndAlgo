#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{

    int t = 1;
    cin >> t;
    for(; t; --t)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(c >= a)
        {
            cout << 1 << '\n';
            continue;
        }
        if(c <= (a+b) / 2)
        {
            cout << 2 << '\n';
            continue;
        }
        long long  st = 1;
        long long  dr = (1LL<<40);
        ll mini = 0;
        double te = 0;
        while(st <= dr)
        {
            ll mid = (st + dr) / 2;
            ll sum = 1LL * mid * a + 1LL * (mid-1) * b;
            double avg = (0.0000 + sum) / (0.0000 + mid + mid - 1);
            if(avg >= c)
                mini = mid, st = mid + 1;
            else
                dr = mid - 1;
        }
        te = (a + b) / 2;
        ll ans = 2;
        for(ll mid = mini; mid <= mini + 100; mid++)
        {
            ll sum = 1LL * mid * a + 1LL * (mid-1) * b;
            double avg = (0.0000 + sum) / (0.0000 + mid + mid - 1);
            if(abs(avg - c) < abs(te - c))
            {
                ans = mid+mid-1;
                te = avg;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}