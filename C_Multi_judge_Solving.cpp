#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, k; cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    ll ans = 0;
    while(pq.size()) {
        ll curr = pq.top(); pq.pop();
        // cout << curr << '\n';
        while(curr > k * 2LL) {
            k *= 2LL;
            ++ans;
            // cout << ans << ' ' << k << '\n';
        }
        k = max(k, curr);
    }

    cout << ans << '\n';

    return 0;   
}