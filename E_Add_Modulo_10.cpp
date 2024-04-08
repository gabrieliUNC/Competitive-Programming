#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


ll target;

ll normalize(ll n) {
    while(n % 10 != 2) {
        n += (n % 10);
    }
    return n;
}

bool get(ll n) {
    ll dist = (target - n) / 20LL;
    n += (dist * 20LL);

    while(n < target) {
        n += (n % 10);
    }

    // cout << n << '\n';

    return n == target; 
}


int solve() {

    int n; cin >> n;
    vector<ll> a(n);
    
    bool zero = 0;

    for(auto& e : a) {
        cin >> e;
        if (e % 10 == 0 || e % 10 == 5) zero = 1;
    }

    if(zero) {
        for(auto& e : a) e = e + (e % 10);
        ll cur = a[0];
        for(int i = 1; i < n; ++i) if(a[i] != cur) return 0;
        return 1;
    }

    for(auto& e : a) e = normalize(e); 
    // cout << '\n';

    target = *max_element(begin(a), end(a));


    for(auto&e : a) if(!get(e)) return 0;


    return 1;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) cout << (solve() ? "Yes\n" : "No\n");




    return 0;
}