#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    map<ll, ll> map;
    ll col = 0;
    for(ll i = 0; i < n; ++i){
        ll temp; cin >> temp;
        map[i] = temp;
        col = max(col, temp);
    }
    ll ans = 0, cnt = 0;
    bool prod = 1;
    for(auto [f, s] : map){
        if(s > 1 && (s == col && !prod)){
            ans += (s - 1);
            ++cnt;
        }
        // else if (s == col){
        //     prod = 0;
        //     if(s > n - 1)ans += (s - (n - 1));
        //     else ans += (s - 1);
        //     ++cnt;
        // }
    }

    if(n==1 || cnt == 0)ans = 0;

    cout << ans << '\n';




    return 0;
}