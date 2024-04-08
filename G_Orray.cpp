#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

constexpr int UD = 1e9 + 9;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        A[i].F = tmp;
        A[i].S = tmp;
    }

    sort(begin(A), end(A), [](const auto& a, const auto& b) {
        return a.S > b.S;
    });
    

    int have = 0;
    vector<int> ans;
    for(int i = 31; i >= 0; --i) {
        int want = 1 << i;
        if(want & have) continue;

        for(auto& [tmp, e] : A) if(e != UD) e ^= (e & have);
        sort(begin(A), end(A), [](const auto& a, const auto& b) {
            return a.S > b.S;
        });

        for(int i = 0; i < n; ++i) {
            if(A[i].S == UD) continue;
            if(A[i].S & want) {
                ans.push_back(A[i].F);
                have |= A[i].S;
                A[i].S = UD;
                break;
            }
        }
    }

    sort(begin(A), end(A), [](const auto& a, const auto& b) {
            return a.S > b.S;
    });
    for(int i = 0; i < n; ++i) if(A[i].S != UD) ans.push_back(A[i].F);
    

    for(auto& e : ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();

    return 0;
}