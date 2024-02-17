#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr ll MOD = 998244353;

using item = array<int, 5>;

map<item, ll> mp;

ll dfs(int prev, int a, int b, int c, int d) {
    if(a == 0 && b == 0 && c == 0 && d == 0) return mp[{prev, a, b, c, d}] = 1LL;

    cout << prev << ' ';
    ll ans = 0;

    if(prev == 1 || prev == -1) {
        if(b) ans += (dfs(2, a, b - 1, c, d)) % MOD;
        if(c) ans += (dfs(3, a, b, c - 1, d)) % MOD;
    }

    if(prev == 2 || prev == -1) {
        if(a) ans += (dfs(1, a - 1, b, c, d)) % MOD;
        if(d) ans += (dfs(4, a, b, c, d - 1)) % MOD;
    }

    if(prev == 3 || prev == -1) {
        if(b) ans += (dfs(2, a, b - 1, c, d)) % MOD;
        if(c) ans += (dfs(3, a, b, c - 1, d)) % MOD;
    }

    if(prev == 4 || prev == -1) {
        if(a) ans += (dfs(1, a - 1, b, c, d)) % MOD;
        if(d) ans += (dfs(4, a, b, c, d - 1)) % MOD;
    }

    // cout << ans << '\n';
    return mp[{prev, a, b, c, d}] = ans % MOD;
}

int main() {

    int tt; cin >> tt;

    while(tt--) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        cout << dfs(-1, a, b, c, d) / 2 << '\n';

    }




    return 0;
}