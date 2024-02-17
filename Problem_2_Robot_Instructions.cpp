#include <bits/stdc++.h>
#define ll long long
using namespace std;


map<pair<ll, pair<ll, ll>>, ll> l, r;


int main() {
    int n; cin >> n;
    ll x, y; cin >> x >> y;
    vector<pair<int, int>> a(n);
    for(auto &e : a) cin >> e.first >> e.second;

        for(int bit = 1; bit < (1 << n / 2); ++bit) {
            ll curr_x = 0, curr_y = 0;
            for(int i = 0; i < n / 2; ++i) {
                if(bit & (1 << i)) {
                    curr_x += a[i].first;
                    curr_y += a[i].second;
                }
            }
            
            // l.insert_or_assign({__builtin_popcount(bit), {curr_x, curr_y}}, l[{__builtin_popcount(bit), {curr_x, curr_y}}] + 1);
            l[{__builtin_popcount(bit),{curr_x, curr_y}}]++;
        }
    

        for(int bit = 1; bit < (1 << ((n + 1) / 2)); ++bit) {
            ll curr_x = 0, curr_y = 0;
            for(int i = 0; i < (n + 1) / 2; ++i) {
                if(bit & (1 << i)) {
                    curr_x += a[i + (n / 2)].first;
                    curr_y += a[i + (n / 2)].second;
                }
            }

            // r.insert_or_assign({__builtin_popcount(bit), {curr_x, curr_y}}, r[{__builtin_popcount(bit), {curr_x, curr_y}}] + 1);
            r[{__builtin_popcount(bit),{curr_x, curr_y}}]++;
        }

    ll ans[n + 1];

    for(int size = 1; size <= n; ++size) {
        ans[size] = l[{size, {x, y}}] + r[{size, {x, y}}];
        for(auto& [params, cnt] : l) {
            if((ll) size - params.first <= 0) continue;
            pair<ll, pair<ll, ll>> complement = {(ll)size - params.first, {x - params.second.first, y - params.second.second}};
            if(r.count(complement)) {
                ans[size] += (cnt * r[complement]);
            }
        }
    }

    for(int size = 1; size <= n; ++size) {
        cout << ans[size] << '\n';
    }


    return 0;
}