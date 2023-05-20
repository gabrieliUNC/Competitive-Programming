#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;

int n, dp[N][2];
vector<int> g[N];

void dfs(int v, int par){
    for(int u : g[v]){
        if(u != par){
            dfs(u, v);
        }
    }
    dp[v][0] = 0;
    for(int u : g[v]){
        if(u != par){
            dp[v][0] += max(dp[u][0], dp[u][1]);
        }
    }
    for(int u: g[v]){
        if(u != par){
            dp[v][1] = max(dp[v][1], dp[v][0] - max(dp[u][0], dp[u][1]) + dp[u][0] + 1);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    cout << max(dp[1][1], dp[1][0]) << '\n';

}