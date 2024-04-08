#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;



void solve() {
    int n; cin >> n;
    vector<ll> a(n), ans;
    for(auto& e : a) cin >> e;
    sort(begin(a), end(a));

    int range = a[n - 1] - a[0];

    int i = 1, j = n - 1;
    ll curr = a[0];
    ans.reserve(n);
    ans.pb(a[0]);

    bool ok = 1;

    while(i <= j) {
        if(abs(curr + a[i]) < range) {
            ans.pb(a[i]);
            curr += a[i++];
        }
        else if(abs(curr + a[j]) < range) {
            ans.pb(a[j]);
            curr += a[j--];
        }
        else {
            ok = 0;
            break;
        }
    }

    if(ok && n != 1) {
        cout << "Yes\n";
        for(auto e : ans) cout << e << ' ';
        cout << '\n';
    } else cout << "No\n";


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tt; cin >> tt;
    while(tt--) solve();


    return 0;
}