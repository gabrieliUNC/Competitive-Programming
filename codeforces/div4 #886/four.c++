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

int main(){
    START
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ull expected; cin >> expected;
        vector<ll> a(n);
        sort(a.begin(), a.end(), greater<int>());

        for(int i = 0; i < n; ++i) cin >> a[i];

        if(n == 1){
            expected = sqrt(expected);
            cout << (expected - a[0]) / 2 << '\n';
            continue;
        }

        ull l = 0, r = 1e18;

        ull ans = 0;


        while (r - l > 1){
            ull mid = (l + r) / 2;
            ans = 0;

            for(ll elt : a){
                ans += ((elt + (2 * mid)) * (elt + (2 * mid)));
            }
            if(ans <= expected) l = mid;
            else r = mid;
        }
        cout << l << '\n';
    }



    return 0;
}

                                 
