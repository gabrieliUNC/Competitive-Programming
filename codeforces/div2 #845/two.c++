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

const ll inf = 1e18 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;



const int MOD = 1e9 + 7;
const int mxN = 10e5 + 7;
ll f[mxN];

int main(){
    START
    
    f[0] = 1;

    for(ll i = 1; i < mxN; ++i){
        f[i] = (f[i-1] * i) % MOD;
    }

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        n += 2;
        ll ans = (n - 2) * (n - 3) % MOD;
        ans = ans * f[n-2] % MOD;
        cout << ans << '\n';
    }



    return 0;
}

                                 
