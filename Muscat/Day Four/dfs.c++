#include <bits/stdc++.h>
using namespace std;

int n, src, dest;

void dfs(int src, vector<vector<int>> &graph, vector<bool> &v, int &dest, vector<int> &p, bool &ok){
    if(v[src] == 1) return;
    else{
        v[src] = 1;
        p.push_back(src);
    }
    if(src == dest) {
        ok = 1; 
        return;
    }
    
    for(int node : graph[src]){
        if(v[node] == 0) dfs(node, graph, v, dest, p, ok);
    }
    return;
}

int main(){
    cin >> n >> src >> dest;

    vector<vector<int>> graph;
    graph.resize(n + 1);

    bool ok = 0;

    vector<bool> v(n, 0);

    vector<int> p;
    p.clear();

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x != 0){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    dfs(src, graph, v, dest, p, ok);

    if(ok){
        cout << p.size() - 1 << '\n';
        for(int node : p) cout << node << ' ';
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }

}