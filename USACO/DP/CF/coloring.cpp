#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17 + 8;
const int mxN = 1e2 + 7;
ll dp[mxN][mxN][mxN];

int main(){
    int n, k, m; cin >> n >> m >> k;
    vector<ll> a(n);
    vector<vector<ll>> p(n, vector<ll>(m, 0));
    for(auto& e : a) cin >> e;
    for(auto &v : p) for(auto& e : v) cin >> e;


    for(int i = 0; i < mxN; ++i)
        for(int j = 0; j < mxN; ++j)
            for(int y = 0; y < mxN; ++y)
                dp[i][j][y] = inf;

    if(a[0] == 0){
        for(int i = 1; i <= m; ++i) dp[0][1][i] = p[0][i - 1];
    } else{
        dp[0][1][a[0]] = 0;
    }

    for(int i = 1; i < n; ++i){ //trees
        for(int j = 1; j <= min(i+1, k); ++j){ //number of sets
            for(int l = 1; l <= m; ++l){ //end color

                if(a[i] != 0){ //colored
                    if(l == a[i]) dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j][l]);
                    else{
                        dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j - 1][l]);
                    }
                } 

                else{ //not colored
                    dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j][l] + p[i][l - 1]);
                    for(int x = 1; x <= m; ++x){
                        if(x != l) dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j - 1][x] + p[i][l - 1]);
                    }
                }           
            }
        }
    }



    ll ans = inf;
    for(int i = 1; i <= m; ++i){
        ans = min(ans, dp[n - 1][k][i]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';

    return 0;
}