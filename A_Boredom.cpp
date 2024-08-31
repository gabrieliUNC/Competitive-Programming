#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int mxN = 1e5 + 7;
int A[mxN], freq[mxN];
int n, bound = 0;


map<pair<int, bool>, ll> dp;

ll dfs(int num, bool took) {
    if(dp.count({num, took})) return dp[{num, took}];
    if(num > bound) return dp[{num, took}] = 0LL;
    
    ll dontTake = dfs(num + 1, 0), take = 0LL;

    if(!took) {
        take = (ll)num * (ll)freq[num] + dfs(num + 1, 1);
    }

    return dp[{num, took}] = max(take, dontTake);

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        freq[A[i]]++;
        bound = max(bound, A[i]);
    }


    cout << dfs(1, 0) << '\n';


    return 0;
}