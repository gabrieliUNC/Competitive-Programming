#include <bits/stdc++.h>
using namespace std;


int n, m;
constexpr int mxN = 1e5 + 7;
int h[mxN];
vector<vector<int>> g;
vector<vector<int>> rooted;


int dfs(int u, int p, int cats) {
    // cout << u << '\n';
    int ans = 0;

    if(h[u]) ++cats;
    else cats = 0;

    if(cats > m) return 0;
    if(rooted[u].empty()) return 1;

    for(int v : rooted[u]) {
        if(v == p) continue;
        ans += dfs(v, u, cats);
    }

    return ans;
}



int main() {
    cin >> n >> m;
    g.resize(n);

    for(int i = 0; i < n; ++i) cin >> h[i];

    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    stack<int> c;
    c.push(0);
    rooted.resize(n);

    vector<int> vis(n, 0);

    while(size(c)) {
        int u = c.top(); c.pop();
        vis[u] = 1;
        for(int v : g[u]) {
            if(vis[v]) continue;
            rooted[u].push_back(v);
            c.push(v);
        }
    }


    cout << dfs(0, -1, 0) << '\n';


    return 0;
}