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
#define rall(x) (x).rbegin(), (x).rend()
#define START ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                                                            
#define CPU cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#define vi vector<int>;
#define vvi vector<vi>;
#define pii pair<int, int>;
#define vpii vector<pii>;

const int MOD = 1e9 + 7;
const ll inf = 1e18 + 5;
const ld pi = 3.1415292654589793;
const int maxn = 1e5 + 5;

int main(){
    START
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr (n); ll prefix[n] = {0};
        loop(i, n){
            cin >> arr[i];
        }
        int ones = 0;
        loop(i, n){
            if(i!=0)prefix[i]=prefix[i-1];
            if(arr[i]==1)ones++;
            else prefix[i]+=ones;
        }

        ll ans = prefix[n-1];

        vector <int> cpy(all(arr));
        int i=0;
        bool ok = false;
        while(i<n){
            if(cpy[i]==0){ok = true; break;}
            i++;
        }
        if(ok)cpy[i]=1;
        fill_n(prefix, n, 0);
        ones = 0;
        loop(i, n){
            if(i!=0)prefix[i]=prefix[i-1];
            if(cpy[i]==1)ones++;
            else prefix[i]+=ones;
        }
        ans = max(ans, (ll)prefix[n-1]);

        
        i=n-1;
        ok = false;
        vector<int> cpy2(all(arr));
        while(i>=0){
            if(cpy2[i]==1){ok = true; break;}
            i--;
        }
        if(ok)cpy2[i] = 0;
        fill_n(prefix, n, 0);
        ones = 0;
        loop(i, n){
            if(i!=0)prefix[i]=prefix[i-1];
            if(cpy2[i]==1)ones++;
            else prefix[i]+=ones;
        }
        ans = max(ans, (ll)prefix[n-1]);
        cout << ans << '\n';

    }



    return 0;
}

                                 
