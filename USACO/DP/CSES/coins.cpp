#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, target; cin >> n >> target;
    vector<int> c(n);
    for(int i = 0; i < n; ++i) cin >> c[i];

    int dp[target + 1];
    dp[0] = 0;

    for(int i = 1; i <= target; ++i){
        dp[i] = 1e9 + 7;
        for(auto coin : c){
            if(coin <= i){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[target] == 1e9 + 7 ? -1 : dp[target]) << '\n';



    return 0;
}