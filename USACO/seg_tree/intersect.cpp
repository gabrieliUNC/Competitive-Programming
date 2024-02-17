#include <bits/stdc++.h>
using namespace std;

template <class T> class SegmentTree{
    private:
        const T DEFAULT = 0;

        vector<T> segtree;
        int len;
    
    public:
        SegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

        void set(int ind, T v){
            ind += len;
            segtree[ind] = v;
            for(; ind > 1; ind /= 2){
                segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
            }
        }

        int range_sum(int start, int end){
            T op = DEFAULT;
            for(start += len, end += len; start < end; start /= 2, end /= 2){
                if(start % 2) { op += segtree[start++]; }
                if(end % 2) { op += segtree[--end]; }
            }

            return op;
        }
};

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

int n;
vector<int> a, ans;

void solve(){
    SegmentTree<int> t(n);
    vector<int> v(n / 2, -1);
    
    for(int i = 0; i < n; ++i){
        if(v[a[i]] != -1){
            t.set(v[a[i]], 0);
            ans[a[i]] += t.range_sum(v[a[i]], i);
        } else{
            v[a[i]] = i;
            t.set(i, 1);
        }
        
    }
}


int main(){
    cin >> n; n *= 2;
    ans.resize(n / 2, 0);
    a.resize(n);

    for(auto &e : a) {cin >> e; e--; }

    solve();
    reverse(a.begin(), a.end());
    solve();
    
    for(auto e : ans) cout << e << ' ';
    cout << '\n';

    return 0;
}