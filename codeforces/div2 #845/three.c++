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
        int n, m; cin >> n >> m;
        vector<int> a(n);
        loop(i, n)cin >> a[i];
        sort(all(a));
        int high = -1;
        for(int i = n - 1; i >= 0; --i){
            if(a[i]%m==0){
                high = a[i];
                break;
            }
        }
        if(high-1==1){
            cout << 0 << '\n';
            continue;
        }
        if(high==-1){
            cout << -1 << '\n';
            continue;
        }
        int i;
        for(i = m - 1; i > 3; --i){
            if(!binary_search(all(a), i))break;
        }
        if(i==3){
            cout << high - 4 << '\n';
            continue;
        }
        else{
            cout << -1 << '\n';
            continue;
        }

    }



    return 0;
}

                                 
