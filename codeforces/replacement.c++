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
    ll arr[n];
    ll high = -1 * inf;
    int high_i = 0;
    ll low = inf;
    int low_i = 0;
    loop(i, n){
        cin >> arr[i];
        if(arr[i]>high){
            high = arr[i];
            high_i = i;
        }
        if(arr[i]<low && arr[i]!=1){
            low = arr[i];
            low_i = i;
        }
    }

    if(high==1){
        arr[low_i] = high+1;
    }
    else{
        arr[high_i] = 1;
    }

    sort(arr, arr+n);
    for(ll e: arr){
        cout << e << ' ';
    }


    return 0;
}

                                 
