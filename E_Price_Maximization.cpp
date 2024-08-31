#include <bits/stdc++.h>
#define ll long long
using namespace std;


constexpr int mxN = 1e3 + 1;
vector<stack<int>> mod(mxN);

void solve() {
    int n, k; cin >> n >> k;
    

    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        mod[tmp % k].push(tmp);
    }

    // for(int i = 0; i < k; ++i) sort(begin(mod[i]), end(mod[i]));


    ll ans = 0;

    for(int i = 0; i < k; ++i) {
        if(!n) break;
        if(mod[i].empty()) continue;
        for(int dist = 0; dist < k; ++dist) {
            int target = k - i; // how far we are from mod k

            int idx = (target + dist) % k;

            while(mod[i].size() && mod[idx].size()) {
                if(i == idx && mod[i].size() < 2) break;

                int f = mod[i].top(); mod[i].pop();
                int s = mod[idx].top(); mod[idx].pop();
                // cout << f << ' ' << s << '\n';

                ans += ((f + s) / k);
                n -= 2;
            }
            if(!n) break;
        }
        
    }

    
    std::cout << ans << '\n';

    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}