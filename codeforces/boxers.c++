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
const ld pi = 3.1415292654589793;
const int maxn = 1e5 + 5;

int main(){
    START
        int n; cin >> n;
        int arr[n];
        loop(i, n) cin >> arr[i];
        set<int> s;
        sort(arr, arr+n);
        loop(i, n){
            if(arr[i]-1>0){if(s.insert(arr[i]-1).second) continue;}
            if(s.insert(arr[i]).second)continue;
            if(arr[i]+1<=150001)s.insert(arr[i]+1);
        }
        set<int> t;
        sort(arr, arr+n, greater<int>());
        loop(i, n){
            if(arr[i]+1<=150001){if(t.insert(arr[i]+1).second)continue;}
            if(t.insert(arr[i]).second)continue;
            if(arr[i]-1>0)t.insert(arr[i]-1);
        }

        cout << (s.size()>t.size() ? s.size() : t.size());
        
    


    return 0;
}

                                 
