#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;
const int inf = -1e8 - 7;
int dp[mxN][mxN];
int a[mxN][mxN];

int main(){
    for(int i = 0; i < mxN; ++i){
        for(int j = 0;  j < mxN; ++j){
            dp[i][j] = inf;
            a[i][j] = inf;
        }
    }
    // freopen("slalom.in","r",stdin);
    // freopen("slalom.out","w",stdout);
    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i + 1; ++j){
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];

    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            if(j < i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < mxN; ++i) ans = max(ans, dp[n - 1][i]);
    cout << ans << '\n';

    return 0;
}