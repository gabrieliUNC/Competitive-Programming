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

    for(int i = 0; i < N; ++i) dp[0][i] = 1ULL;

    for(int i = 1; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(j > 0) dp[i][j] += (ull) dp[i][j - 1];
            if(i > 0) dp[i][j] += (ull) dp[i - 1][j];
        }
    }

    int m, n; cin >> m >> n;
    --m;
    --n;


    cout << grid(m, n) << '\n';


    return 0;
}