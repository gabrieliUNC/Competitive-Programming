#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
constexpr int mxN = 2e5 + 7;
int vis[mxN];

int dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        return 1 + dfs(v);
    }
    return 1;
}

bool solve() {
    int n; cin >> n;
    g.clear();
    g.resize(n);
    memset(vis, 0, sizeof(vis));
    bool ok = 1;

    for(int i = 0; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);

        if(u == v || size(g[u]) > 2 || size(g[v]) > 2) ok = 0;
    }

    if(!ok) return 0;

    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            if(dfs(i) % 2) return 0;
        }
    }



    return 1;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) cout << (solve() ? "YES\n" : "NO\n");




    return 0;
}