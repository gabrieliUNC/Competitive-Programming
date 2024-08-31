#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, int> freq;

constexpr int mxN = 2e5 + 8;
int A[mxN];

void solve() {
    freq.clear();
    int n, ans = 0; cin >> n;
    vector<ll> p = {0};

    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        p.push_back((ll) A[i] + p.back());
    }

    int num = 0;

    for(int i = n - 1; i >= 0; --i) {
        freq[p[i + 1]]++;
        num = max(num, freq[p[i + 1]]);

        if(A[i] == 0) {
            ans += num;

            freq.clear();
            num = 0;
        }
        
    }

    for(int i = 0; i < n; ++i) {
        if(A[i] == 0) break;
        if(p[i + 1] == 0) ++ans;
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();





    return 0;
}