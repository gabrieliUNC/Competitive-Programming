#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, m; cin >> n >> m;
    int dp[n][m + 1];
    memset(dp, 0, sizeof(dp));
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    if(!a[0]) for(int i = 1; i <= m; ++i) dp[0][i] = 1;
    else dp[0][a[0]] = 1;

    for(int i = 1; i < n; ++i){
        if(!a[i]){
            for(int j = 1; j <= m; ++j){
                for(int k = j - 1; k <= j + 1; ++k){
                    if(k >= 1 && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= MOD;
                }
            }
        } else{
            for(int j = a[i] - 1; j <= a[i] + 1; ++j){
                if(j >= 1 && j <= m)
                    (dp[i][a[i]] += dp[i - 1][j]) %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i){
        (ans += dp[n - 1][i]) %= MOD;
    }

    cout << ans << '\n';



    return 0;
}