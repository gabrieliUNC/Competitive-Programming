#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n + 1, 0);
    int l = 1, r = n, op = 1;

    for(int i = 1; i <= n; ++i) {
        if(a[i]) {
            op ^= 1;
            continue;
        }
        if(op) {
            for(int j = i; j <= n; j += k) {
                a[j] = l++;
            }
        }
        else {
            for(int j = i; j <= n; j += k) {
                a[j] = r--;
            }
        }
        op ^= 1;
    }

    for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';

}

int main() {
    int tt; cin >> tt;

    while(tt--) solve();



    return 0;
}