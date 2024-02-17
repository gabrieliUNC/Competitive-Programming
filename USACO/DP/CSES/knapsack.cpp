#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 3, b = 3;
    int dp[n][b + 1]; memset(dp, 0, sizeof(dp));

    int v[n] = {4, 5, 3};

  int w[n] = {2, 3, 1};

    for(int i = 0; i <= b; ++i){
        if(w[0] <= i) dp[0][i] = v[0];
    }


    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= b; ++j){
            if(w[i] <= j){
                dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            } else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

cout << "============================\n";

for(int i = 0; i < n; ++i){
    for(int j = 0; j <= b; ++j){
        cout << dp[i][j] << ' ';
    }
    cout << '\n';
}

cout << "============================\n";

cout << dp[n - 1][b] << '\n';

    return 0;
}