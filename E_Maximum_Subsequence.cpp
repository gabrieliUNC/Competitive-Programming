#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> l, r;

int main() {
    int n, MOD; cin >> n >> MOD;
    int A[n];
    for(auto &e : A) cin >> e;

    l.reserve(1 << 16);
    r.reserve(1 << 16);

    ll ans = 0;


    for(int bit = 1; bit < (1 << (n / 2)); ++bit) {
        ll sum = 0;
        for(int i = 0; i < n / 2; ++i) {
            if(bit & (1 << i)) {
                sum += A[i];
                sum %= MOD;
            }
        }
        l.push_back(sum);
        ans = max(ans, sum);
    }

    for(int bit = 1; bit < (1 << ((n + 1) / 2)); ++bit) {
        ll sum = 0;
        for(int i = 0; i < (n + 1) / 2; ++i) {
           if(bit & (1 << i)) {
            sum += A[i + (n / 2)];
            sum %= MOD;
           } 
        }
        r.push_back(sum);
        ans = max(ans, sum);
    }

    sort(r.begin(), r.end());

    for(auto num : l) {
        int pos = distance(r.begin(), upper_bound(r.begin(), r.end(), MOD - num - 1));

        for(int i = max(0, pos - 2); i < min((int) r.size(), pos + 3); ++i) {
            ans = max(ans, (ll)((num + r[i]) % MOD));
        }
    }

    cout << ans << '\n';


    return 0;
}