#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ll MOD = 1e9 + 7;

const int mxN = 2e5 + 7;
ll fact[mxN];

ll powmod(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    if(n < k)
        return 0;
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

void solve() {
    int n, k; cin >> n >> k;
    int ones{0};
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        ones += tmp;
    }
    int zeroes = n - ones;

    ll ans = 0;

    for(int want = k / 2 + 1; want <= k; ++want) {
        ans += (nCk(ones, want, MOD) * nCk(zeroes, k - want, MOD)) % MOD;
    }
    ans %= MOD;

    cout << ans << '\n';

}

int main() {
    fact[0] = 1;
    fact[1] = 1;

    for(ll pow = 2; pow < mxN; ++pow) {
        fact[pow] = fact[pow - 1] * pow;
        fact[pow] %= MOD;
    }

    int tt; cin >> tt;
    while(tt--)
        solve();



    return 0;
}