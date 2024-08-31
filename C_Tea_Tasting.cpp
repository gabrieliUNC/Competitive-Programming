#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Fen {
    vector<int> bit;  // binary indexed tree
    int n;

    Fen(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0LL);
    }


    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

};

const int mxN = 2e5 + 7;
ll ans[mxN];
int A[mxN], tasters[mxN];
vector<ll> pre;

void solve() {
    memset(ans, 0, sizeof(ans));
    int n; cin >> n;
    pre = {0LL};
    

    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n; ++i) {
        cin >> tasters[i];
        pre.push_back(pre.back() + tasters[i]);
    }


    Fen fenny(n + 2);

    for(int i = 0; i < n; ++i) {
        int target = A[i];
        auto it = upper_bound(begin(pre) + i, end(pre), target + pre[i]);
        
        if(it != begin(pre) + i) it--;
        int pos = distance(begin(pre), it);

        // cout << i << ' ' << pos << '\n';

        fenny.range_add(i, pos - 1, 1);
        ll tmp = target - (pre[pos] - pre[i]);
        // cout << tmp << '\n';
        ans[pos] += min(tmp, (ll) tasters[pos]);
    }

    // for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
    // cout << '\n';
    for(int i = 0; i < n; ++i) cout << (ll) fenny.point_query(i) * (ll) tasters[i] + ans[i] << ' ';
    cout << '\n';



}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;

    while(tt--) solve();





    return 0;
}