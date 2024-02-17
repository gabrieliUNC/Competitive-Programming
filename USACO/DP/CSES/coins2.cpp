#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, target; cin >> n >> target;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= target; ++i){
        for(auto coin : coins){
            if(coin <= i){
                dp[i] += dp[i - coin];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[target] % MOD << '\n';


    return 0;
}