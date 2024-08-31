#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

map<int, ll> freq;

pair<ll, ll> f(ll x, ll y) {
    return {(-x + (sqrt(x * x - 4 * -1 * -y))) / -2, (-x - (sqrt(x * x - 4 * -1 * -y))) / -2};
}

void solve() {
    freq.clear();
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        freq[tmp]++;
    }

    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        ll x, y; cin >> x >> y;

        pair<ll, ll> ans = f(x, y);
        // cout << ans.first << ' ' << ans.second << '\n';

        if(ans.first + ans.second != x || ans.first * ans.second != y) cout << 0 << ' ';
        else if(ans.first == ans.second) cout << ( (freq[ans.first] - 1) * freq[ans.second] ) / 2 << ' ';
        else cout << freq[ans.first] * freq[ans.second] << ' ';
    }

    cout << '\n';
    


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();



    return 0;
}