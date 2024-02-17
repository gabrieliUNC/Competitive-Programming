#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T> class Seggie {
    private:
        const T DEFAULT = 0;

        vector<T> segtree;
        int len;

    public:
        Seggie(int len): len(len), segtree(len * 2, DEFAULT) {}

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
                if(start % 2) op += segtree[start++];
                if(end % 2) op += segtree[--end];
          
            }
            return op;
        }
};

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), a_p(n, 0), b_p(n, 0);
    Seggie<ll> seg_a(n), seg_b(n);
    for(auto &e : a){
        cin >> e;
        --e;
    }
    for(auto &e : b) {
        cin >> e;
        --e;
    }

    for(int i = 0; i < n; ++i){
        a_p[i] = seg_a.range_sum(a[i], n);
        seg_a.set(a[i], 1);
    }

    for(int i = 0; i < n; ++i){
        b_p[i] = seg_b.range_sum(b[i], n);
        seg_b.set(b[i], 1);
    }

    int cnt_1 = 0, cnt_2 = 0;
    for(int i = 0; i < n; ++i){
        cnt_1 += a_p[i];
        cnt_2 += b_p[i];
    }

    cout << ((cnt_1 % 2) == (cnt_2 % 2) ? "Possible\n" : "Impossible\n");
    



    return 0;
}