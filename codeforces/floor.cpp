#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    if(n == 1) {cout << 0 << '\n'; return; }
    int l = *min_element(a.begin(), a.end()), r = *max_element(a.begin(), a.end());
    int ans;
    if(r != l) ans = log2(r - l) + 1;
    else ans = 0;

    cout << ans << '\n';
    if(ans <= n && ans != 0){
        while(l < r){
            int x = l % 2;
            cout << x << ' ';
            l = ( l + x ) / 2;
            r = ( r + x ) / 2;
        }

    }
    cout << '\n';
    
}

int main(){
    int t; cin >> t;
    while(t--) solve();



    return 0;
}
