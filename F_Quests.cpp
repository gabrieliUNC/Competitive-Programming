#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int BOUND = 2;

bool check(priority_queue<int> pq, int k, int &d, ll &c) {
    int t[d + 1]; memset(t, 0, sizeof(t));

    ll sum = 0LL;
    for(int day = 1; day <= d; ++day) {
        if(t[day] != 0) pq.push(t[day]);
        if(pq.size()) {
            int cur = pq.top(); pq.pop();
            sum += cur;
            if(day + k + 1 <= d) t[day + k + 1] = cur;
        }
        if(sum >= c) return 1;
    }
    // cout << '\n';

    // cout << k << ' ' << sum << '\n';

    return sum >= c;
}

void solve() {
    int n, d;
    ll c, ans = 0LL;
    cin >> n >> c >> d;

    priority_queue<int> pq;
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    if(!check(pq, 0, d, c)) {
        cout << "Impossible\n";
        return;
    }

    int l = 0, r = 1e9 + 7;

    while(l < r) {
        int mid = l + (r - l) / 2;
        // cout << mid << '\n';
        bool ok = 0;
        for(ll j = mid; j < mid + BOUND; ++j) {
            if(check(pq, j, d, c)) {
                ans = j;
                ok = 1;
            }
        }

        if(ok) {
            l = mid + 1;
        }
        else r = mid - 1;
    }

    if(ans > 1e9) cout << "Infinity\n";
    else cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();


    return 0;
}