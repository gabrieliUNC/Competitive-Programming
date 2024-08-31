#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) begin(x), end(x)
using namespace std;



void solve() {
    int n, s, t; cin >> n >> s >> t;
    vector<pair<int, int>> tasks(n);
    for(auto& e : tasks)
        cin >> e.F >> e.S;
    sort(all(tasks));

    bool ok = false;
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        if(tasks[i].F - cur >= s)
            ok = true;
        cur = tasks[i].S;
    }
    if(t - tasks[n - 1].S >= s)
        ok = true;
    
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();



    return 0;
}