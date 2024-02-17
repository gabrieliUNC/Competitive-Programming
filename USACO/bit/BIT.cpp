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

};