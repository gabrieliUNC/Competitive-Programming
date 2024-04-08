#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 998244353;

int findTwos(int lower, int upper) {
    int cur = 0, factor = 1;
    for(int sz = 0; sz < 32; ++cur) {
        if(lower * factor > upper) break;
        factor *= 2;
    }

    return cur;
}


void solve() {
    ll l, r; cin >> l >> r;

    int sz = max(findTwos(l, r), 1);

    ll ans = (r / pow(2, sz - 1) - l + 1);
    ans %= MOD;
    if(sz > 1)  ans += (sz - 1) * max(0LL, (r / ((ll)pow(2, sz - 2)) / 3 - l + 1)) % MOD;

    cout << sz << ' ' << ans << '\n';

}


int main() {

    int tt; cin >> tt;


    while(tt--) solve();




    return 0;
}