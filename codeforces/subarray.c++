#include<bits/stdc++.h>
using namespace std;

long long dp[5001];


int main(){
    int t; cin >> t;
    const long long neg_inf = -1e16;
    while(t--){
        int n;
        long long x; cin >> n; cin >> x;
        int arr[n];
        for(int i=0; i<n; ++i) cin >> arr[i];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = neg_inf;
        }
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                sum += arr[j];
                dp[len] = max(dp[len], sum);
            }
        }
        for (int k = 0; k < n + 1; ++k) {
            long long opt = 0;
            for(int i=1; i<=n; ++i){
                opt = max(opt, dp[i] + x*min(k, i));
            }
            cout << opt << ' ';
        }
        cout << '\n';

    }

    return 0;
}