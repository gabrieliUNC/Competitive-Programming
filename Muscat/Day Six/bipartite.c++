#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int n, m, t[N];
vector<int> g[N];
bool ok = 1;

void dfs(int v){
    for(int u : g[v]){
        if(t[u] == t[v]){
            ok = 0;
            return;
        }
        else if (t[u] == 0){
            if(t[v] == 1){
                t[u] = 2;
                dfs(u);
            }
            else{
                t[u] = 1;
                dfs(u);
            }
        }
    }   
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(t[i] == 0){
            t[i] = 1;
            dfs(i);
        }
    }

    if(ok){
        cout << "YES" << '\n';
        for(int i = 1; i <= n; ++i){
            cout << t[i] << ' ';
        }
        cout << '\n';
    } else{
        cout << "NO" << '\n';
    }

    return 0;
}