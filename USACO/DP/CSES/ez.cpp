#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    ll MOD = 1e9 + 7;
    ll dp[n + 1]; 
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int sum = 1; sum <= n; ++sum){
        for(int die = 1; die <= 6; ++die){
            if(die <= sum) dp[sum] += dp[sum - die];
            else break;
        }
        dp[sum] %= MOD;
    }

    cout << dp[n] << '\n';


    return 0;
}