#include <bits/stdc++.h>
#define ld long double
using namespace std;

void solve(){
    int n; cin >> n; ld d, h; cin >> d >> h; ld ans = h * d * n / 2;

    vector<ld> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    for(int i = 1; i < n; ++i){
        if(a[i] < a[i - 1] + h){
            ld h2 = h + a[i - 1] - a[i];
            ld d2 = d / h * h2;
            ans -= h2 * d2 / 2;
        }
    }

    cout << fixed;
    cout.precision(8);
    cout << ans << '\n';
}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();

    return 0;
}