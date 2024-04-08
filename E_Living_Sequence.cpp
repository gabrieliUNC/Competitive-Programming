#include <bits/stdc++.h>
#define ll long long
using namespace std;




auto digits(ll num) {
    ll rem = (num / 10LL);
    for(ll div = 100; div <= 1e12; div *= 10LL) {
        rem += max((num / div) * div / 10LL - (div / 100LL), 0LL);
    }

    for(ll div = 100; div <= 1e12; div *= 10LL) {
        if(num % div >= 4LL * (div / 10LL)) {
            rem += max(div / 10LL - (div / 100LL), 0LL);
        }
    }

    return rem;
}

void solve() {
    ll num; cin >> num;

    ll prev = digits(num);
    
    for(int it = 1; it <= 10; ++it) {
        prev = digits(num + prev);
    }
    cout << num + prev << '\n';
    
}

int main() {

    int tt; cin >> tt;

    while(tt--) solve();





    return 0;
}