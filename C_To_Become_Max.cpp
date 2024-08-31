#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
using namespace std;

ll eval(ll guess, int idx, vector<ll>& a) {
    int j = idx, steps = 1;

    while(j + 1 < (int) size(a) && (a[j] > a[j + 1] || a[j + 1] + steps < guess)) {
        // cout << "{ " << a[j] << ", " << a[j + 1] << " } " << ' ' << steps << '\n';
        j++;
        steps++;
    }
    
    if(j == size(a) - 1)
        return INT_MAX;

    steps--;
    ll cost = 0;
    while(j >= idx) {
        // a[j] += cur - a[j] - steps;
        // cout << "{ " << a[j] << " } " << ' ' << guess - a[j] - steps << '\n';

        cost += guess - a[j] - steps;
        steps--;
        j--;
    }
    return cost;
}


void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto& e : a)
        cin >> e;

    ll ans = *max_element(all(a));

    for(int i = 0; i < n - 1; ++i) {
        ll l = a[i], r = 1e15;
        if(a[i] < a[i + 1]) {
            ans = max(ans, min(a[i] + k, a[i + 1] + 1LL));
        }

        while(l <= r) {
            ll mid = l + (r - l) / 2;
            ll dif = k - eval(mid, i, a);
            if(dif >= 0) {
                l = mid + 1;
                ans = max(ans, mid);
            } else r = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();



    return 0;
}