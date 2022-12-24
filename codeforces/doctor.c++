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
    
    int s, b; cin >> s >> b;
    vector <ll> ships(s); loop(i, s) cin >> ships[i];
    vector <pair<ll, ll>> bases(b);
    loop(i, b){
        ll p, q; cin >> p >> q;
        bases[i] = {p, q};
    }
    sort(all(bases));

    vector <ll> prefix(b);
    loop(i, b){
        prefix[i] = bases[i].second;
        if(i) prefix[i] += prefix[i-1];
    }
    ll inf = (ll)(1e9 + 10);
    loop(i, s){
        ll ship = ships[i];
        ll temp = upper_bound(bases.begin(), bases.end(), make_pair(ship, inf)) - bases.begin() - 1;
        cout << (temp>=0 ? prefix[temp] : 0) << '\n';
    }


    return 0;
}

                                 
