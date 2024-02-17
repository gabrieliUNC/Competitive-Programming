#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define sz(x) (int)x.size()
template<typename FUNCTION>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define loopd(x, n) for(int x = n; x>=0; --x)
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define START ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                                                            
#define CPU cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#define vi vector<int>;
#define vvi vector<vi>;
#define pii pair<int, int>;
#define vpii vector<pii>;

const int MOD = 1e9 + 7;
const ll inf = 1e18 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

template <class T> using ordered_tree = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    START
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for(auto &e : a) cin >> e.first >> e.second;
        ordered_tree<ll> st;

        sort(a.rbegin(), a.rend());
        ll ans = 0;

        for(auto [l, r]: a){
            ans += st.order_of_key(r + 1);
            st.insert(r);
        }

        cout << ans << '\n';


        
    }



    return 0;
}

                                 
