#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, pos; cin >> n >> pos;
    // cout << ((n * (n + 1)) / 2) << '\n';
    int neg = ((n * (n + 1)) / 2) - pos;

    vector<int> a;
    vector<int> p = {1};
    for(int i = 2; i <= n; ++i) p.push_back(p.back() + i);
    

    // cout << neg << '\n';
    // for(auto& e : p) cout << e << ' ';
    // cout << '\n';

    int i = 0;
    for(; i < n; ++i) {
        if(p[i] > neg) { neg -= p[i - 1]; break; }
        a.push_back(-2);
    }
    if(i == n) goto end;

    // cout << neg << '\n';
    if(neg > 0) {
        int sum = min(1 + 2 * (i - neg), 1000);
        // cout << i - neg << '\n';
        a.push_back(sum);
        i++;
        for(i; i < n; ++i) a.push_back(1000);
    }

    end:
    while(size(a) < n) a.push_back(1000);

    reverse(begin(a), end(a));
    // cout << "=========================\n";

    for(int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';

}


int main() {
    int tt; cin >> tt;
    while(tt--) solve();



    return 0;
}