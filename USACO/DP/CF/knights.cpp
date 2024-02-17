#include <bits/stdc++.h>
using namespace std;

const int mxN = 55;
int dp[mxN][mxN];


int main(){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    int n, m; cin >> n >> m;

    for(int i = 0; i < mxN; ++i){
        for(int j = 0; j < mxN; ++j){
            dp[i + 1][j + 2] += dp[i][j];
            dp[i + 2][j + 1] += dp[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << '\n';


    return 0;
}