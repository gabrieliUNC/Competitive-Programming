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
        vector<int> pos, neg(n);
        pos.resize(0);
        neg.resize(0);
        fill(neg.begin(), neg.end(), 0);

        bool zero = 0;
        loop(i ,n){
            int temp; cin >> temp;
            if(temp < 0)neg.pb(temp);
            else if(temp > 0)pos.pb(temp);
            else zero = 1;
        }
        sort(neg.begin(), neg.end());
        for(int e: pos)cout << e << '\n';
        if(neg.size()){
            for(int i = 0; i + 1 < n; i+=2){
                int f = neg[i];
                int s = neg[i + 1];
                if(f!=0 && s!=0){
                    cout << f << '\n';
                    cout << s << '\n';
                }
                else break;
            }
        }
        if((!pos.size()) && (neg.size() < 2) && (zero == 1))cout << 0 << '\n';
        else if((!pos.size()) && (neg.size() < 2) && (zero == 0)) cout << neg[n - 1] << '\n';
        



    return 0;
}

                                 
