#include <bits/stdc++.h>
using namespace std;


const int mxN = 1e3 + 7;
int dp[mxN][2];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 1;
    

    for(int i = 0; i < n; ++i) cin >> a[i];
    
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(dp[j][0] && a[i] - a[j] > 0) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            if(dp[j][1] && a[i] - a[j] < 0) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';





    return 0;
}