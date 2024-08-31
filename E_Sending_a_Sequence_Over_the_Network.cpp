#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 2e5 + 7;
int A[mxN];
bool mp[mxN];
int n;

void solve() {
    cin >> n;
    memset(mp, false, (n + 1) * sizeof(bool));
    for(int i = 0; i < n; ++i) cin >> A[i];
    if(n == 1) {
        cout << "NO\n";
        return;
    }
    
    mp[0] = true;

    for(int i = 1; i <= n; ++i) {
        int jump = A[i - 1];
        if(i + jump <= n && mp[i - 1] == true) mp[i + jump] = true;
        if(i - jump - 1 >= 0 && mp[i - jump - 1] == true) mp[i] = true;
    }

    cout << (mp[n] ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();
}