#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int mxN = 1e5 + 7;
bool primes[mxN];
int len, sp[mxN];

void Sieve(){
	for (int i = 2; i < mxN; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < mxN; i += 2){
		if (!primes[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < mxN; j += 2){
				if (!primes[j*i])	primes[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

vector<int> factorize(int k) {
	vector<int> ans;
	while(k > 1) {
		ans.push_back(sp[k]);
		k /= sp[k];
	}
	return ans;
}


pair<int, int> solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    auto factors = factorize(a);
    auto tmp = factorize(b);
    for(auto f : tmp) factors.push_back(f);
    factors.push_back(1);
    factors.push_back(1);

    // for(auto f : factors) cout << f << ' ';
    // cout << '\n';

    ll n = size(factors);
    // cout << n << '\n';
    // return {0, 0};
    for(ll i = 1; i <= (1 << (n - 1)); ++i) {
        ll x = 0, y = 0;
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                if(!x) x = factors[j];
                else x *= factors[j];
            }
            else {
                if(!y) y = factors[j];
                else y *= factors[j];
            }
        }
        if(x > c || y > d || x == 0 || y == 0) continue;

        bool ok = 0;

        

        // cout << x << ' ' << y << '\n';

        for(ll mult = 1LL; x * mult <= c; mult++) {
            ll cur = x * mult;
            if(cur > a && cur <= c) {
                x = cur;
                ok = 1;
                break;
            }
        }

        if(!ok) continue;
        ok = 0;

        for(ll mult = 1LL; y * mult <= d; mult++) {
            ll cur = y * mult;
            if(cur > b && cur <= d) {
                y = cur;
                ok = 1;
                break;
            }
        }


        // for(ll j = a + 1; j <= c; ++j) 
        //     if(j % x == 0) {
        //         x = j;
        //         ok = 1;
        //         break;
        //     }

        // if(!ok) continue;
        // ok = 0;
        // for(ll j = b + 1; j <= d; ++j)
        //     if(j % y == 0) {
        //         y = j;
        //         ok = 1;
        //         break;
        //}

        if(ok) {
            return {x, y};
        }

    }

    return {-1, -1};
}

int main() {
    Sieve();
    int tt; cin >> tt;
    while(tt--) {
        auto ans = solve();
        cout << ans.first << ' ' << ans.second << '\n';
    }




    return 0;
}