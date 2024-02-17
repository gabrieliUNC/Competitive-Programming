#include <bits/stdc++.h>
using namespace std;

using cycle = pair<int, vector<int>>;
constexpr int mxN = 2e5 + 7;
vector<vector<pair<int, int>>> g;
cycle ans;
int visited[mxN];

void dfs_cycle(int u, pair<int, int> p, int color[], pair<int, int> par[], int smallest)
{
    // cout << p.first << ':' << p.second << '\n';
    visited[u] = 1;
    // cout << u << '\n';

    if (color[u] == 2) {
        return;
    }
 
    if (color[u] == 1) {
        if(smallest < ans.first) {
            // int minn = edges[u][p];
            int minn = par[u].second;
            // int minn = edges[{u, p}];
            vector<int> v;
            
            pair<int, int> cur = p;
            v.push_back(cur.first);
    
            while (cur.first != u) {
                // cout << cur.first << ':' << cur.second << '\n';
                //minn = min(minn, edges[cur][par[cur]]);
                minn = min(minn, cur.second);
                // cout << minn << '\n';
                cur = par[cur.first];
                v.push_back(cur.first);
            }

            if(minn < ans.first) {
                ans.first = minn;
                ans.second = v;
            }
        }
        
        return;
    }
    par[u] = p;
 
    
    color[u] = 1;
 
    for (auto& [v, w] : g[u]) {
 
        if (v == par[u].first) {
            continue;
        }
        dfs_cycle(v, {u, w}, color, par, min(smallest, w));
    }
 
    color[u] = 2;
}


void solve() {
    int n, m; cin >> n >> m;
    g.clear();
    g.resize(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }


    int color[n + 1];
    pair<int, int> par[n + 1]; 
    memset(color, 0, sizeof(color)); memset(par, INT_MAX, sizeof(par)); memset(visited, 0, sizeof(visited));
    ans = {INT_MAX, vector<int>()};

    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;

        dfs_cycle(i, {0, INT_MAX}, color, par, INT_MAX);
    }

    cout << ans.first << ' ' << ans.second.size() << '\n';
    for(auto u : ans.second) cout << u << ' ';
    cout << '\n';
    

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    
    while(tt--) solve();
    



    return 0;
}