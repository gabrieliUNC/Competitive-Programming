#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 7;
const int mxY = 1e5 + 7;
int dp[mxN][mxY];
int main(){
    int n, target; cin >> n >> target;
    vector<int> prices(n), pages(n);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) cin >> prices[i];
    for(int i = 0; i < n; ++i) cin >> pages[i];
    for(int i = 0; i <= target; ++i) if(prices[0] <= i) dp[0][i] = pages[0];

    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= target; ++j){
            if(prices[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i]] + pages[i]);
            } else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 1][target] << '\n';


    return 0;
}