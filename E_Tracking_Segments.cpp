#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) begin(x), end(x)
using namespace std;

const int mxN = 1e5 + 7;
uint32_t A[mxN];

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> segs(m);
    for(auto& e : segs)
        std::cin >> e.F >> e.S;
    
    auto clear = [&n](uint32_t* A) {memset(A, 0, (n + 1) * sizeof(uint32_t));};
    
    int q; cin >> q;
    vector<int> queries(q);
    for(auto &e : queries)
        cin >> e;

    int l = 0, r = q, ans = -1;

    while(l <= r) {
        int mid = (l + r) / 2;
        clear(A);

        // process [:mid] queries
        for(int i = 0; i < mid; ++i)
            A[queries[i]] = 1;
        for(int i = 1; i <= n; ++i)
            A[i] += A[i - 1];
        
        bool ok = false;
        // check segments
        for(const auto& [l, r] : segs) {
            if(A[r] - A[l - 1] >= (r - l + 1) / 2 + 1) {
                ok = true;
                break;
            }
        }
        
        // cout << mid << ' ' << ok << '\n';

        if(ok) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; std::cin >> tt;
    while(tt--)
        solve();




    return 0;
}