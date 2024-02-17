#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ll dp[n + 1][64];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 64; ++j){
            (dp[i][j] += dp[i - 1][j]) %= MOD; // bring all combinations forward
            (dp[i][a[i] & j] += dp[i - 1][j]) %= MOD; // take all combinations with AND
        }
        dp[i][a[i]]++; // start new subsequence
    }

    ll ans = 0;
    
    for(int i = 0; i < 64; ++i){
        if(__builtin_popcount(i) == k) (ans += dp[n][i]) %= MOD;
    }

    return ans;

}

int main(){
    int tt; cin >> tt;
    while(tt--) cout << solve() << '\n';




    return 0;
}