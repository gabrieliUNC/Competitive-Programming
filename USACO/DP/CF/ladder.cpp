#include <bits/stdc++.h>
using namespace std;


const int mxN = 1e5 + 7;
long long int dp[mxN];

int main(){
    fill(dp, dp + mxN, (int)-1e9);
    // freopen("ladder.in", "r", stdin);
    // freopen("ladder.out","w",stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        dp[i] = max(dp[i], dp[i - 1] + a[i - 1]);
        if(i > 1) dp[i] = max(dp[i], dp[i - 2] + a[i - 1]);
    }

    cout << dp[n] << '\n';


    return 0;
}