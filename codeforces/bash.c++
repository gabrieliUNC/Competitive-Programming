/*
** Date: !v strftime("%A, %d %B, %Y")`
** Time: !v strftime("%X")`
*/

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
    
    int n; cin >> n;
    vector <int> in(n);
    loop(i, n) cin >> in[i];
    set<int> mod;
    int ans = 0;
    loop(i, n){
        bool ok = true;
        int root = sqrt(in[i]);
        for(int j = 2; j<=root; ++j){
            if(in[i]%j==0){
                if(mod.insert(j).second==false)ok = false;
            }
        }
        if(mod.insert(in[i]).second==false)ok=false;
        if(ok)ans++;
    }

    for(int e: mod) cout << e << '\n';
    cout << endl;
    
    cout << ans << '\n';




    return 0;
}

                                 
