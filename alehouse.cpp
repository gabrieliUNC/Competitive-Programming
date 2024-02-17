#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    vector<pair<ll, bool>> times;

    for(int i = 0; i < n; ++i){
        ll a, b; cin >> a >> b;
        a = max(a - k, 0LL);
        times.push_back({a, 0});
        times.push_back({b, 1});
    }
    sort(times.begin(), times.end());
    
    int ans = 0, tmp = 0;
    for(auto time : times){
        if (time.second) --tmp;
        else ++tmp;

        ans = max(ans, tmp);
    }

    cout << ans << '\n';

    return 0;
}