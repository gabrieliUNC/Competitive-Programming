#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> a(n);
    ll s[n + 1] = {0};
    for(auto &e : a) cin >> e;

    for(int i = n - 1; i >= 0; --i){
        s[i] = s[i + 1] + a[i];
    }

    ll ans = s[0];
    for(int i = 1; i < n; ++i) if(s[i] > 0) ans += s[i];

    return ans;

}

int main(){
    int tt; cin >> tt;
    while(tt--) cout << solve() << '\n';



    return 0;
}