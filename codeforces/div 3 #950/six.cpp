#include "bits/stdc++.h"
using namespace std;

#define int long long 

const int N = 1e5 + 7;
const int B = 3e2 + 5;;
int pre[B][N+B]{},S[B][N+B]{};
 
void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];

    for (int d = 1; d < B; d++) {
        for (int i = 0; i < n; i++) {
            S[d][i + d] = S[d][i]+ a[i] * (i / d+1);
            pre[d][i + d] = pre[d][i] + a[i];
        }
    }

    while(q--){
        int s,d,k;
        cin>>s>>d>>k;
        s--;

        if ( d >= B) {
            int ans = 0;
            for (int i = 0; i < k; i++) {
                ans += a[s + d * i] * (i + 1);
            }
            cout << ans << ' ';
        } else {
            int r = s + d * k;
            cout << S[d][r] - S[d][s] - (s / d) * (pre[d][r] - pre[d][s]) << ' ';
        }
    }
    cout << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}