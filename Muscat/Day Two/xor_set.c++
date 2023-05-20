#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> basis;

    for (ll x: a) {
        ll temp = x;
        for (ll b: basis) temp = min(temp, (temp^b));
        if (temp) basis.push_back(temp);
    }

    ll ans = 0;

    for(ll a: basis){
        ll temp = a;
        for(ll b : basis){
            if((temp ^ b) > temp) (temp ^= b);
        }
        ans = max(ans, temp);
    }
    
    ans = max(ans, *max_element(a.begin(), a.end()));

    cout << ans << '\n';
    

    return 0;   
}
