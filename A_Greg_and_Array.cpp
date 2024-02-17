#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Fen {
    vector<ll> bit;  // binary indexed tree
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

    void range_add(int l, int r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }

    ll point_query(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

static const int N = 1e5 + 7;
Fen fenny(N);
Fen ops(N);


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < n; ++i) {
        ll tmp; cin >> tmp;
        fenny.range_add(i, i, tmp);
    }


    // for(int i = 0; i < n; ++i) cout << fenny.point_query(i) << ' ';
    // cout << '\n';
    vector<vector<ll>> op(m, vector<ll>(3));
    for(auto &e : op) {
        cin >> e[0] >> e[1] >> e[2];
        e[0]--;
        e[1]--;
    }

    for(int i = 0; i < k; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;
        ops.range_add(l, r, 1LL);
    }

    for(int i = 0; i < m; ++i) {
        ll num = ops.point_query(i);
        fenny.range_add(op[i][0], op[i][1], op[i][2] * num);
    }

    for(int i = 0; i < n; ++i) cout << fenny.point_query(i) << ' ';

    



    return 0;
}