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
const int maxn = 1e5 + 5;

int main(){
    START
    
    int n, q; cin >> n >> q;
    int k = sqrt(n);
    vector<ll> a(n);
    loop(i, n) cin >> a[i];

    vector<ll> b(k + 9, 0);
    loop(i, n) b[i / k] += a[i];
    //precalculate sum

    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll pos, x; cin >> pos >> x;
            pos--;
            a[pos] = x;
            //set new_elt
            int id = pos / k;

            int l = (id) * k;
            int r = min(((int)(((id) + 1) * k)) - 1, n);

            //bounds of block
            b[id] = 0;
            //reset block

            while(l <= r){
                b[id] += a[l++];
            }
            //recalculate block
        }
        else{
            int l, r; cin >> l >> r;
            l--; r--;
            int i = l;
            ll temp = 0;


            while(i <= r){
                if((i % k == 0) && (i + k - 1 <= r)){
                    //start of block and block inside query
                    temp += b[i / k];
                    i += k;
                }
                else{
                    temp += a[i];
                    ++i;
                }
            }
            cout << temp << '\n';
        }
    }


    return 0;
}

                                 
