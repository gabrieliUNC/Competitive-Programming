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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        map<char, int> m;
        for(char c: s){
            m[c]++;
        }
        ll ans = 0;
        ll extra = 0;
        for(pair<char, int> p : m){
            if((int) p.first >= 97){
            if(m.count(toupper(p.first))) {
                ans += min(m[p.first], m[toupper(p.first)]);
                extra += abs(m[p.first] - m[toupper(p.first)]) / 2;
                }
                else{
                    extra += m[p.first] / 2;
                }
            }
            else if (!m.count(tolower(p.first))){
                extra += m[p.first] / 2;
            }
        }

        ans += min(k, extra);
        cout << ans << '\n';

    }



    return 0;
}

                                 
