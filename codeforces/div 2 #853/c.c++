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
        int n; cin >> n;
        string str; cin >> str;
        int start = 0;
        int end = n - 1;
        int half = n /2;

        while(start < half){
            if(str[start] != str[end]) break;
            start++;
            end--;
        }

        if(start == half) { cout << "YES" << '\n'; continue; }

        while(start < half){
            if(str[start] == str[end]) break;
            if(str[start] == '1') str[start] = '0';
            else str[start] = '1';
            start++;
            end--;
        }

        bool ok = 1;

        for(int i = 0; i < n; ++i){
            if(str[i] != str[n - i - 1]){
                ok = 0;
                break;
            }
        }
        
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }



    return 0;
}

                                 
