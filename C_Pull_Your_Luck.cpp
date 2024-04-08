#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll calc(ll p) {
    return (((1LL + (p)) * (p)) / 2LL);
}


bool solve() {
    ll n, x, p; cin >> n >> x >> p;
    
    for(int i = 1; i <= min(n * 2 + 1, p); ++i) if((x + calc(i)) % n == 0LL) return 1;


    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) cout << (solve() ? "Yes\n" : "No\n");



    return 0;
}