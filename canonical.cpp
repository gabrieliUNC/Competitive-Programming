#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n; cin >> n;
    vector<int> coins(n);
    for(auto &e : coins) cin >> e;

    int sz = coins[n - 2] + coins[n - 1];
    vector<int> dp(sz, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i < sz; ++i){
        for(auto coin : coins){
            if(i - coin >= 0) dp[i] = min(dp[i], dp[i - coin] + 1);
            else break;
        }

        

        int pos = distance(coins.begin(), upper_bound(coins.begin(), coins.end(), i)) - 1;
        int cnt = 0, num = i;
        for(pos; pos >= 0; --pos){
            int dem = coins[pos];
            cnt += (num / dem);
            num %= dem;
            if(num == 0) break;
        }

        if(dp[i] != cnt) {
            return 0;
        }
    }

    return 1;
}

int main(){
    
    cout << (solve() == 1 ? "canonical\n" : "non-canonical\n");

    return 0;
}