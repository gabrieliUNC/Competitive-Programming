#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll avg(ll l, ll h){ return (l + h) / 2; }

void solve(){
    int n; cin >> n;

    vector<ll> a(n); for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    
    int low = -1, high = 1e9 + 7;

    while(high - low > 1){
        int mid = (high + low) >> 1;
        int cnt = 0;
        ll max = 0;
        for(int i = 0; i < n; ++i){
            if(max < a[i]) max = a[i] + (mid * 2), ++cnt;
        }

        // cout << ' ' << low << ' ' << mid << ' ' << high << '\n';

        if(cnt > 3) low = mid;
        else high = mid;
    }

    cout << high << '\n';




}

int main(){
    int tt; cin >> tt;
    while(tt--) solve();





    return 0;
}