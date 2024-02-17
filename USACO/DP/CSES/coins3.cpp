#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, target; cin >> n >> target;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];
    int dp[target + 1]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= target; ++j){
            if(coins[i] <= j){
                dp[j] += dp[j - coins[i]];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[target] % MOD << '\n';

    return 0;
}