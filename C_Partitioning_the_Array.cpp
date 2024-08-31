#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

vector<int> factorize(int k) {
	vector<int> res;
    for(int i = 1; i < k; ++i)
        if(k % i == 0)
            res.push_back(i);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for(auto& e : A)
        cin >> e;

    int ans = 1;
    auto factors = factorize(n);

    for(const auto& k : factors) {
        // cout << k << '\n';

        int g = 0;
        for (int i = 0; i + k < n; i++)
            g = __gcd(g, abs(A[i + k] - A[i]));
        ans += (g != 1);
    }

    std::cout << ans << '\n';

}


int main() {

    int tt; cin >> tt;
    while(tt--)
        solve();



    return 0;
}