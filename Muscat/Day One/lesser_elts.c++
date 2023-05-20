#include <bits/stdc++.h>
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

void merge(vector<ll> &s , vector<ll> &a){
    for(ll e: a)s.pb(e);
    sort(all(s));
    a.clear();
}

void upd(vector<ll> &s, vector<ll> &a, ll &x, int &k){
    a.pb(x);
    if(a.size() >= k) merge(s, a);
}

int get(vector<ll> &s, vector<ll> &a, ll &x){
    ll ans = 0;

    vector<ll>::iterator low;
    low = lower_bound(s.begin(), s.end(), x);
    ans += (low - s.begin());

    for(ll e: a){
        if(e < x)++ans;
    }
    return ans;
}

int main(){
    START
    
    int q; cin >> q;
    int k = sqrt(q); // set block size

    vector<ll> s; // sorted set
    vector<ll> a; // non-included queries
    while(q--){
        //query decomp
        int t; cin >> t;
        ll x; cin >> x;

        if(t == 1){
            upd(s, a, x, k);
        }
        else{
            cout << get(s, a, x) << '\n';
        }


    }




    return 0;
}

                                 
