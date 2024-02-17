#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T> class SegmentTree {
    private: 
        const T DEFAULT = 0;
        vector<T> segtree;
        int len;
    
    public:
        SegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

        void set(int ind, T val){
            ind += len;
            segtree[ind] = val;
            for(; ind > 1; ind /= 2){
                segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
            }
        }

        T range_sum(int start, int end){
            T op = DEFAULT;
            for(start += len, end += len; start < end; start /= 2, end /= 2){
                if(start % 2) {op += segtree[start++]; }
                if(end % 2) {op += segtree[--end]; }
            }
            return op;
        }
};

int main(){
    int n; cin >> n;
    n *= 2;
    vector<int> a(n), v(n, -1), ans(n / 2);
    for(auto &e : a) { cin >> e;  }
    SegmentTree<ll> t(n);
    
    for(int i = 0; i < n; ++i){
        a[i]--;
        if(v[a[i]] != -1){
            ans[a[i]] = t.range_sum(v[a[i]], i);
            t.set(v[a[i]], 1);
        }
        v[a[i]] = i;
    }

    for(auto e : ans) cout << e << ' ';
    cout << '\n';


    return 0;
}