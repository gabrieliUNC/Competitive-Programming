#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve(){
    int n, q, t; cin >> n >> q >> t;
    int size = -1;
    ll ans = 0;

    for(int i = 0; i < n; ++i){
        ll temp; cin >> temp;
        if(temp > t) size = i;
        ans += max(0, i - size - q + 1);
    }

    cout << ans << '\n';


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();



    return 0;
}