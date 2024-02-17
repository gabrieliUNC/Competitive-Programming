#include <bits/stdc++.h>
using namespace std;


const int mxN = 2e5 + 8;
const int inf = 1e9 + 8;
int dp[mxN][2];

int solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = inf;
    dp[0][1] = 0; //friend
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            for(int fight = 1; fight <= min(n - i, 2); ++fight){
                int hard = a[i] + (fight > 1 ? a[i + 1] : 0);
                dp[i + fight][!j] = min(dp[i + fight][!j], dp[i][j] + j * hard);
            }
        }
    }

    return min(dp[n][0], dp[n][1]);

}

int main(){
    int tt; cin >> tt;
    while(tt--){
        cout << solve() << '\n' << '\n';
    }



    return 0;
}