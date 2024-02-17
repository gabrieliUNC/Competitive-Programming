#include <bits/stdc++.h>
using namespace std;




void solve() {
    int n, m, k, l = 0, r = 0, extra = 0; cin >> n >> m >> k;

    vector<int> found(k + 1, 0);
    
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        if(tmp <= k) {
            if(!found[tmp]) {
                found[tmp] = 1;
                ++l;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        if(tmp <= k) {
            if(found[tmp] == 1) {
                found[tmp] = 2;
                --l;
                ++extra;
            }
            else if(found[tmp] == 0) {
                found[tmp] = 2;
                ++r;
            }
        }
    }

    // cout << l << ' ' << r << ' ' << extra << '\n';

    bool ok = 1;
    for(int i = 1; i <= k; ++i) if(!found[i]) ok = 0;

    if(!ok || min(l, r) + extra < (k / 2)) cout << "NO\n";
    else cout << "YES\n";



}


int main() {
    int tt; cin >> tt;

    while(tt--) solve();




    return 0;
}