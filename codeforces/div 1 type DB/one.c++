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

ll eq(ll a, ll b){
    return (pow(a, b) * b + (pow(b, a) * a));
}


int main(){
    START
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> d;
        d.clear();
        
        for(ll i = 1; i * i < n; ++i){
            if(n % i == 0 && i * i != n)d.pb(n / i), d.pb(i);
            if(n % i == 0 && i * i == n)d.pb(i);
        }
        sort(all(d));
        int i, j;

        for(i = 0; i < d.size(); ++i){
            bool ok = 0;
            for(j = i; j < d.size(); ++j){
                if(eq(d[i], d[j]) == n){
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }

        if(eq(d[i], d[j]) == n) cout << d[i] << ' ' << d[j] << '\n';
        else cout << -1 << '\n';
    
    }



    return 0;
}

                                 
