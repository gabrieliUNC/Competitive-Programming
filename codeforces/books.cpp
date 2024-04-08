#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(auto& e: a) cin >> e;

    int l = 0, cost = a[0], ans = 0;
    if(cost <= t) ans = 1;
    for(int r = 1; r < n; ++r) {
        cost += a[r];
        while(cost > t) {
            cost -= a[l];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    
    cout << ans << '\n';
}