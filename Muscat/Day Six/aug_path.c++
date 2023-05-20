#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;

int x, y, m; 

vector<int> g[N];
int match[N];
bool visited[N];

bool aug(int v) {
    if (visited[v]) return false;
    visited[v] = true;

    for (int u : g[v])
        if (match[u] == -1) {
            match[u] = v;
            return true;
        }
 
    for (int u : g[v]) {
        bool can = aug(match[u]);
        if (can) {
            match[u] = v;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> x >> y >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= y; i++) match[i] = -1;

    for (int v = 1; v <= x; v++) {
        aug(v);
        for (int i = 1; i <= x; i++) visited[i] = 0;
    }

    vector<pair<int, int>> res;

    for (int i = 1; i <= y; i++) if (match[i] != -1) res.push_back({match[i], i});

    cout << res.size() << '\n';

    for (int i = 0; i < res.size(); i++) cout << res[i].first << ' ' << res[i].second << "\n";


    return 0;
}