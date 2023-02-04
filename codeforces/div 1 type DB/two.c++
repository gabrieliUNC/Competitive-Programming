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
const ll inf = 1e9 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;


int main(){
    START
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<int, int>> f;
        for(int i = 2; i * i <= n; ++i){
            if(n % i == 0){
            int d = 0;
            while(n % i == 0){
                n /= i;
                ++d;
            }
            f.pb({i, d});
            }
        }
        if(n > 1)f.pb({n, 1});
        ll ans = 0;
        for(int i = 1; i < 107; ++i){
            int temp = 1;
            for(int j = 0; j < f.size(); ++j){
                if(f[j].second >= i) temp *= f[j].first;
            }
            if(temp != 1)ans += temp;
            else break;
        }

        cout << ans << '\n';

        
    }



    return 0;
}

                                 
