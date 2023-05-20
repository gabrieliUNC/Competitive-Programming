#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5;
const ll inf = 1e7;

int main(){
    int n, s, f; cin >> n >> s >> f;
    vector<vector<int>> g;
    g.resize(n + 1);
    vector<ll> dist(N, inf);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int temp; cin >> temp;
            if(temp){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while(pq.size()){
        auto [weight, node] = pq.top(); pq.pop();

        if(dist[node] != weight) continue;

        for(int u : g[node]){
            if (dist[u] > dist[node] + 1) {
                dist[u] = dist[node] + 1;
                pq.push({dist[u], u});
            }
        }
    }
    if(dist[f] != inf) cout << dist[f] << '\n';
    else cout << 0 << '\n';


}