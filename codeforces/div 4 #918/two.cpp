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
        char g[3][3];
        unordered_map<char, int> v;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                cin >> g[i][j];

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(g[i][j] == '?'){
                    for(int x = 0; x < 3; ++x){
                        if(x == i) continue;
                        v[g[x][j]] = 1;
                    }
                    for(int y = 0; y < 3; ++y){
                        if(y == j) continue;
                        v[g[i][y]] = 1;
                    }
                }
            }
        }

        for(char pos = 'A'; pos < 'D'; ++pos){
            if(!v.count(pos)) cout << pos << '\n';
        }
        
        
    }



    return 0;
}

                                 
