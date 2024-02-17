#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4 + 7;
int dp[mxN];

int main(){
    // freopen("lepus.in","r",stdin);
    // freopen("lepus.out","w",stdout);
    int n; cin >> n;
    string s; cin >> s;
    fill(dp, dp + mxN, -1);
    dp[0] = 0;

    for(int i = 1; i < n; ++i){
        if(s[i] == 'w') continue;
        int curr = s[i] == '"' ? 1 : 0;
        if(dp[i - 1] != -1) dp[i] = max(dp[i], dp[i - 1] + curr);
        if(i > 2 && dp[i - 3] != -1) dp[i] = max(dp[i], dp[i - 3] + curr);
        if(i > 4 && dp[i - 5] != -1) dp[i] = max(dp[i], dp[i - 5] + curr);
    }

    cout << dp[n - 1] << '\n';


    return 0;
}