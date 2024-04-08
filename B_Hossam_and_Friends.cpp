#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i) a[i] = n;

        for(int i = 0; i < m; ++i) {
            int l, r; cin >> l >> r;
            if(l > r) swap(l, r);

            a[l] = min(a[l], r - 1);
        }

        
        for(int i = n - 1; i >= 1; --i) {
            a[i] = min(a[i], a[i + 1]);
        }

        ll ans = n;
        for(int i = 1; i <= n; ++i) ans += a[i] - i;

        cout << ans << '\n';
    }
}