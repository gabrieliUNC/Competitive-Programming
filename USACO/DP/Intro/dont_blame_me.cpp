#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 7;
vector<int> dp[mxN];

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[0].push_back(a[i]);
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            for(int elt : dp[j]){
                int curr = elt & a[i - 1];
                if(curr == k) ++ans;
                dp[i].push_back(curr);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}