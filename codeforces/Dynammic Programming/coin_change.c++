#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
int dp[N];
const int inf = 1e9 + 3;

int solve(int target, vector<int> coins){
    if(target == 0) return 0;
    if(dp[target] != -1) return dp[target];

    int ans = inf;
    for(int coin : coins){
        if(target >= coin){
            ans = min(ans, solve(target - coin, coins) + 1);
        }
    }

    dp[target] = ans;
    return ans;
}

int main(){
    memset(dp, -1, N);
    int n; cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    int target; cin >> target;

    int ans = solve(target, coins);
    if(ans >= inf) ans = -1;


    return 0;
}