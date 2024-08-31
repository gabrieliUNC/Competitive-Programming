#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0; cin >> n;

    for(int i = 1; i <= n; ++i) {
        ans += ((2 * i) - 1) * i;
    }
    
    cout << ans << ' ';
    cout << 2 * n << '\n';

    for(int t = n - 1; t >= 0; --t) {
        cout << 1 << ' ' << t + 1 << ' ';
        for(int i = 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';

        cout << 2 << ' ' << t + 1 << ' ';
        for(int i = 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }

}

int main() {
    int tt; cin >> tt;

    while(tt--) solve();



    return 0;
}