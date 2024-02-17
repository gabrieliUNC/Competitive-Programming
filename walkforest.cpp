#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> rgraph;
vector<int> dist;

unordered_map<int, int> vis;

int dfs(int u) { 
    if(vis.count(u)) return vis[u];
    // cout << u << '\n';

    int ans = 0;

    for(auto [weight, v] : rgraph[u]) {
        if(dist[v] < dist[u]) ans += dfs(v);
    }
    
    return vis[u] = ans;

}

int solve(int n) {
    int m; cin >> m;
    rgraph.clear();
    rgraph.resize(n);

    for(int i = 0; i < m; ++i) {
        int u, v, weight; cin >> u >> v >> weight;
        --u; --v;
        rgraph[v].push_back({weight, u});
        rgraph[u].push_back({weight, v});
    }

    // Dijkstra on Reverse Graph
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.clear();
    dist.resize(n, INT_MAX);    

    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size()) {
        auto [weight, node] = pq.top(); pq.pop();
        if(dist[node] != weight) continue;

        for(auto [distance, neighbor] : rgraph[node]) {
            if(weight + distance < dist[neighbor]) {
                dist[neighbor] = weight + distance;
                pq.push({weight + distance, neighbor});
            }
        }
    }

    vis.clear();
    vis[1] = 1;
    return dfs(0);
}


int main() {

    int t; cin >> t;

    while( t != 0 ) {
        cout << solve(t) << '\n'; 
        cin >> t;
    }




    return 0;
}