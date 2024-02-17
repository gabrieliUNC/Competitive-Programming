#include <bits/stdc++.h>
#define ll long long
using namespace std;


template <class T> class SegmentTree{
    private:
        const T DEFAULT = 0;

        int len;
        vector<T> segtree;
    
    public:
        SegmentTree(int len): len(len), segtree(len * 2, DEFAULT) {}

        void set(int ind, T val){
            ind += len;
            segtree[ind] += val;
            for(; ind > 1; ind /= 2) segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
        }

        int range_sum(int start, int end){
            T op = DEFAULT;
            for(start += len, end += len; start < end; start /= 2, end /= 2){
                if(start % 2) op += segtree[start++];
                if(end % 2) op += segtree[--end];
            }
            return op;
        }
};

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n + 1, 0);
    SegmentTree<ll> t(n + 1);

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        t.set(i, a[i] - a[i - 1]);
    }


    for(int i = 0; i < q; ++i){
        int a; cin >> a; --a;
        if(a){
            int pos; cin >> pos;
            cout << t.range_sum(1, pos + 1) << '\n';
        }
        else{
            ll l, r, amt; cin >> l >> r >> amt;
            t.set(l, amt);
            t.set(r + 1, -amt);
        }
    }


    return 0;
}