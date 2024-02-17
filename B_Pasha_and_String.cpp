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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    int m; cin >> m;
    int Q[m]; 
    for(auto &e : Q) cin >> e;

    Fen fenny(n + 1);

    for(auto l : Q) {
        fenny.range_add(l, n - l + 1, 1);
    }

    for(int i = 1; i <= n / 2; ++i) {
        if(fenny.point_query(i) % 2) {
            swap(s[i - 1], s[n - i]);
        }
    }

    cout << s << '\n';

    return 0;
}