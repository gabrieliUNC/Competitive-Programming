#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(m);
        fill(a.begin(), a.end(), -1);
        for(int i = 0; i < m; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());
        ll ans = 0;
        for(int i = 0; i < m; ++i) ans = max(ans, k * (a[i] - 1) + i + 1);
        cout << (ans <= n ? "YES" : "NO") << '\n';
    }





    return 0;
}