#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int n, q; cin >> n >> q;


    vector<ll> a(n), p(n + 1);


    for(int i = 0; i < n; ++i) cin >> a[i];


    for(int i = 0; i < n; ++i){
        p[i + 1] = a[i] + p[i];
    }


    ll x = 0;
    for(int i = 0; i < q; ++i){
        ll k; cin >> k;
        x += k;
        ll ans;


        if(x >= p[n]){
            ans = n;
            x = 0;
        }else{
            ans = upper_bound(p.begin(), p.end(), x) - p.begin();
            ans = n - ans + 1;
        }
        cout << ans << '\n';
    }


    return 0;
}