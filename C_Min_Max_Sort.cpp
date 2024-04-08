#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    
    auto check = [&](int k) {
        int prev = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] <= k || a[i] >= n - k + 1) continue;
            if(a[i] < prev) return 0;
            prev = a[i];
        }
        return 1;
    };

    int l = 0, r = n / 2;

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << '\n';

}

int main() {

    int tt; cin >> tt;
    while(tt--) solve();



    return 0;
}