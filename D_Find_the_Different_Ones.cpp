#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T> class MinSegmentTree {

    private:
        int len;
        pair<T, T> DEFAULT = {1e18, -1};

        vector<pair<T, T>> segtree;

        pair<T, T> combine(pair<T, T> a, pair<T, T> b) {
            if(a.first < b.first) return a;
            return b;
        }
    
    public:
        MinSegmentTree(int n) : len(n), segtree(n * 2, DEFAULT) {}

        void set(int ind, T val) {
            int idx = ind;
            ind += len;
            segtree[ind] = {val, idx + 1};
            for(; ind > 1; ind /= 2) {
                segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
            }
        }

        pair<T, T> range_min(int start, int end) {
            pair<T, T> op = DEFAULT;

            for(start += len, end += len; start < end; start /= 2, end /= 2) {
                if(start % 2) op = combine(op, segtree[start++]);
                if(end % 2) op = combine(op, segtree[--end]);
            }

            return op;
        }
};

template <class T> class MaxSegmentTree {
    private:
        int len;
        pair<T, T> DEFAULT = {0, -1};

        vector<pair<T, T>> segtree;

        pair<T, T> combine(pair<T, T> a, pair<T, T> b) {
            if(a.first > b.first) return a;
            return b;
        }
    
    public:
        MaxSegmentTree(int n) : len(n), segtree(n * 2, DEFAULT) {}

        void set(int ind, T val) {
            int idx = ind;
            ind += len;
            segtree[ind] = {val, idx + 1};
            for(; ind > 1; ind /= 2) {
                segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
            }
        }

        pair<T, T> range_max(int start, int end) {
            pair<T, T> op = DEFAULT;

            for(start += len, end += len; start < end; start /= 2, end /= 2) {
                if(start % 2) op = combine(op, segtree[start++]);
                if(end % 2) op = combine(op, segtree[--end]);
            }

            return op;
        }
};


void solve() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    MinSegmentTree<ll> minseg(n);
    MaxSegmentTree<ll> maxseg(n);

    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        minseg.set(i, tmp);
        maxseg.set(i, tmp);
    }

    int q; cin >> q;

    for(int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        --l;

        const auto& [val1, j] = minseg.range_min(l, r);
        const auto& [val2, k] = maxseg.range_max(l, r);

        // cout << val1 << ' ' << j << '\n';
        // cout << val2 << ' ' << k << '\n';

        if(val1 != val2) cout << j << ' ' << k << '\n';
        else cout << -1 << ' ' << -1 << '\n';

    }

    cout << '\n';

}

int main() {

    int tt; cin >> tt;
    while(tt--) solve();





    return 0;
}