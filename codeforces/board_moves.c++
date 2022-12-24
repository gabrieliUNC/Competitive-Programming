#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    int tt; cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        ll ans = (((n)*((n)+1LL)*((2*n+1LL))/6LL)) - (((n)+1LL)*(n)/2);
        cout << ans << '\n';
    }
    return 0;
}