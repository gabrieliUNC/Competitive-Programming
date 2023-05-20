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
const int maxn = 5e2 + 6;

ll dp[maxn][maxn];

int main(){
    START
    
    int n, m; cin >> n >> m;

    for(int i = 0; i < maxn; ++i){
        for(int j = 1; j < maxn; ++j) dp[i][j] = -1*inf;
    }

    for(int i = 0; i < maxn; ++i) dp[0][i] = 0;

    ll a[n + 1][m + 1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i > 1) dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
            else dp[i][j] = dp[i][j - 1] + a[i][j];
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}

                                 
