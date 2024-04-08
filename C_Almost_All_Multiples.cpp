#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n + 1);
    a[1] = n;
    a[n] = 1;
    for(int i = 2; i < n; ++i) a[i] = i;

    if((n % x == 0)) {
        if(a[1] != x) swap(a[1], a[x]);
        
        int prev = x, i = x + x;
        while(i < n) {
            if(n % i == 0 && i % prev == 0) {
                swap(a[prev], a[i]);
                prev = i;
            }
            i += x;
        }

        for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
        cout << '\n';
    } else cout << -1 << '\n';


}

int main() {
    
    int tt; cin >> tt;
    while(tt--) solve();



    return 0;
}