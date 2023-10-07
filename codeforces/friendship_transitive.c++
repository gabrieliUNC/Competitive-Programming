#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e6 + 8;
ll n, m;
vector<int> g[N];
int v[N];
ll edges, nodes;

void dfs(int node){
    v[node] = 1;
    nodes++;
    edges += g[node].size();
    for(int child : g[node]) if(!v[child]) dfs(child);
}

bool solve(){
    for(int i = 1; i <= n; ++i){
        if(v[i]) continue;
        edges = 0; nodes = 0;
        dfs(i);
        if((nodes * (nodes - 1)) != edges) return 0;
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << (solve() ? "YES" : "NO") << '\n';

    return 0;
}