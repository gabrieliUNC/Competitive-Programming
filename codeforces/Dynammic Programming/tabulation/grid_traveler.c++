#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 1e2 + 7;

ull dp[N][N];

ull grid(int m, int n){
    return dp[m][n];
}


int main(){
    memset(dp, 0, N * N * sizeof(ull));

    dp[1][1] = 1;

    for(int i = 0; i + 1 < N; ++i){
        for(int j = 0; j + 1 < N; ++j){
            dp[i + 1][j] += dp[i][j];
            dp[i][j + 1] += dp[i][j];
        }
    }

    int m, n; cin >> m >> n;


    cout << grid(m, n) << '\n';


    return 0;
}