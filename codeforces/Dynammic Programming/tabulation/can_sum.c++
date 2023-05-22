#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll inf = 1e8 + 7;
bool dp[inf];


int main(){
    memset(dp, 0, inf);

    dp[0] = 1;

    ll n; cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < inf; ++i){
        if(dp[i]) for(ll num: a){
            if(i + num < inf) dp[i + num] = 1;
        }
    }

    ll target; cin >> target;

    cout << boolalpha;
    cout << dp[target] << '\n';

    return 0;
}