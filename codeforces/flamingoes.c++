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
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

int main(){
    START
    int n; scanf("%d", &n);
    ll ans[10005];
    for(int i=2;i<=n; ++i){
        printf("? %d %d\n",1,i);
        fflush(stdout);
        scanf("%d", &ans[i]);
    }
    printf("? 2 %d\n", n);
    fflush(stdout);
    ll temp; scanf("%d", &temp);
    ans[1] = ans[n] - temp;

    for(int i=n; i>1; --i)ans[i]-=ans[i-1];
    printf("!");
    for(int i=1; i<=n; ++i)printf(" %lld", ans[i]);
    printf("\n");
    fflush(stdout);
    
    return 0;
}

                                 
