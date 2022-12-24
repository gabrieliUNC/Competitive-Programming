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
#define rloop(x, n) for(int x = n; x>=0; --x)
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
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    int upper = 0;
    int lower = 0;
        bool ok = s[0]<=90 ? false : true;
        int i = 0;
        while(i<n){
            if(s[i]>=97)ok = true;
            if(ok && s[i]<=90)upper++;
            ++i;
        } 
        ok = s[n-1]>=97 ? false : true;
        i = n-1;
        while(i>=0){
            if(s[i]<=90)ok = true;
            if(ok && s[i]>90)lower++;
            --i;
        }
        ans = lower < upper ? lower : upper;
        cout << 'n' << n << 'u' << upper << ' ' << 'l' << lower << endl;
    cout << ans << endl;



    return 0;
}
