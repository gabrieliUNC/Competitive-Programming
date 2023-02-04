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
        int n, s, r; cin >> n >> s >> r;
        int max = s - r;
        int sum = 0;
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; ++i){
            ans[i] = max;
            sum += ans[i];
        }
        for(int i = 1; i <= n; ++i){
            if(sum == r) break;
            int curr = min(ans[i] - 1, sum - s);
            ans[i] -= curr;
            sum -= curr;
        }
        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';

    }

return 0;
}


                                 
