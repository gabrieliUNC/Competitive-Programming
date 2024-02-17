#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 7;
const int MOD = 1e9 + 7;
int dp[mxN][mxN];

int main(){
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char c; cin >> c;
            if(c == '*') dp[i][j] = -1;
        }
    }
    int curr = 1;
    for(int i = 0; i < n; ++i){ 
        if(dp[i][0] == -1) curr = -1;
        dp[i][0] = curr;
    }
    curr = 1;
    for(int i = 0; i < n; ++i){ 
        if(dp[0][i] == -1) curr = -1;
        dp[0][i] = curr;
    }
    

    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            if(dp[i][j] != -1){
                if(dp[i][j - 1] != -1) dp[i][j] += dp[i][j - 1];
                if(dp[i - 1][j] != -1) dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << max(dp[n - 1][n - 1], 0) << '\n';


    return 0;
}