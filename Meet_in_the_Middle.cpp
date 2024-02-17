#include <bits/stdc++.h>
#define ll long long
using namespace std;


unordered_map<ll, ll> l, r;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    l.reserve(1 << 23);
    r.reserve(1 << 23);

    for(int j = 1; j < (1 << (n / 2)); ++j) {
        ll sum = 0;
        for(int i = 0; i < n / 2; ++i) {
            if(j & (1 << i)) {
                sum += a[i];
            }
        }
        if(sum != 0) l[sum]++;
    }

    for(int j = 1; j < (1 << ((n + 1) / 2)); ++j) {
        ll sum = 0;
        for(int i = 0; i < (n + 1) / 2; ++i) {
            if(j & (1 << i)) {
                sum += a[i + (n / 2)];
            }
        }
        if(sum != 0) r[sum]++;
    }

    ll ans = l[target] + r[target];

    for(auto& [num, cnt] : l) {
        if(r.find(target - num) != r.end()) {
            ans += (cnt * r[target - num]);
        }
    }

    cout << ans << '\n';

    return 0;
}