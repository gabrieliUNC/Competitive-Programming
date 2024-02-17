#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int l = INT_MAX, r = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == 'B') {
            l = min(i, l);
            r = max(i, r);
        }
    }


    if(l == INT_MAX) cout << 0 << '\n';
    else cout << (r - l + 1) << '\n';

    
}


int main() {
    int tt; cin >> tt;


    while(tt--) {
        solve();
    }


    return 0;
}