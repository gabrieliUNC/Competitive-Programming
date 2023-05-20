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
    
    int n; cin >> n;
    vector<char> v(n);
    int dem = 0, rep = 0;

    loop(i, n){
        cin >> v[i];
        if(v[i] == 'D')dem++;
        else rep++;
    }

    if(dem == 0) { cout << 'R' << '\n'; return 0; }
    else if (rep == 0) { cout << 'D' << '\n'; return 0; }

    else{

        int D = 0;
        int R = 0;
        
        loop(i, inf){
            if(v[i % n] == '0') continue;
            if(v[i % n] == 'D'){
                if(R > 0) v[i % n] = '0', R--;
                else D++, rep--;
                    
            }
            else if (v[i % n] == 'R'){
                if(D > 0) v[i % n] = '0', D--;
                else R++, dem--;
                
            }

            if(dem == 0) { cout << 'R' << '\n'; return 0; }
            if(rep == 0) { cout << 'D' << '\n'; return 0; }
        }
    }



    return 0;
}

                                 
