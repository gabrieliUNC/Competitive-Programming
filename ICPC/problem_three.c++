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
    
    vector<int> a(3);
    for(int i = 0; i < 3; ++i)cin >> a[i];
    sort(all(a));
    int ans = a[2];
    int i = 1;
    while(ans >= 0){
        if(ans - a[i] < 0) break;
        else ans -= a[i];
        --i;
    }

    int curr = a[0] + a[1] - a[2];
    if(curr >= 0) ans = min(curr, ans);
    
    cout << ans << '\n';


    return 0;
}

                                 
