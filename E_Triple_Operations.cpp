#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

const int mxN = 2e5 + 7;
int p[mxN];

vector<int> pow_3;

void solve() {
    int l, r; cin >> l >> r;
    int ans = (p[l] - p[l - 1]) * 2;
    ans += p[r] - p[l];

    // cout << "{ ";
    // for(int i = l; i <= r; ++i)
    //     cout << p[i] << ' ';
    // cout << " }\n";
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    int cur = 1;
    for(int pow = 0; pow < 19; ++pow) {
        cur *= 3;
        pow_3.push_back(cur);
    }

    p[0] = 0;
    for(int i = 1; i < mxN; ++i)
        p[i] = p[i - 1] + (distance(begin(pow_3), upper_bound(all(pow_3), i)) + 1);

    while(tt--)
        solve();



    return 0;
}