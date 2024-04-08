#include <bits/stdc++.h>
#define pb push_back
using namespace std;


constexpr int mxN = 1e5+1;
bool primes[mxN];
vector<int> factors;
void sieve() {
    fill(primes, primes + mxN, 1);
    primes[0] = primes[1] = false;
    for (long long i = 2; i < mxN; i++) {
        if (primes[i]) {
            factors.pb(i);
            for (long long j = i * i; j < mxN; j += i)
                primes[j] = false;
        }
    }
}


bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) {
        cin >> e;
    }
    
    unordered_set<int> mp;
    
    for(auto& num : a) {
        for(const auto& factor : factors) {
            if (factor > num) break;
            if (!(num % factor)) {
                if (mp.find(factor) != mp.end()) return 1;
                mp.insert(factor);
                while (!(num % factor))
                    num /= factor;
                
            }
        }
        if (num > 1) {
            if (mp.find(num) != mp.end()) return 1;
            mp.insert(num);
        }
    }


    return 0;
}

signed main() {
    factors.reserve(mxN);
    sieve();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) cout << (solve() ? "YES\n" : "NO\n");


    return 0;
}