#include <bits/stdc++.h>
#define ll long long
using namespace std;


template <class T> class Seggie {
    private:
        const T DEFAULT = 0;

        int len;
        vector<T> segtree;
    
    public:
        Seggie(int len) : len(len), segtree(len * 2, DEFAULT) {}

        void set(int ind, T val){
            ind += len;
            segtree[ind] = val;

            for(; ind > 0; ind /= 2){
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
    vector<int> a(n);
    for(auto &e : a) {
        cin >> e;
        --e;
    }

    Seggie<ll> two_len(n), three_len(n);


    ll ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        ans += three_len.range_sum(0, a[i]);
        ll cnt = two_len.range_sum(0, a[i]);
        two_len.set(a[i], two_len.range_sum(a[i], a[i] + 1) + 1);
        three_len.set(a[i], three_len.range_sum(a[i], a[i] + 1) + cnt);
    }

    cout << ans << '\n';

    return 0;
}