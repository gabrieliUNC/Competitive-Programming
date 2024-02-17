#include<bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5 + 2;
bool vis[mxN];
int pos[mxN];
vector<int> bfs(int u) {
    vector<int> res = {u + 1};
    queue<int> q;
    q.push(pos[u]);
    
    while(q.size()) {
        int v = q.front();
        if(v == u) break;
        if(vis[v + 1]) return {};
        vis[v + 1] = 1;
        res.push_back(v + 1); q.pop();
        q.push(pos[v]);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;


    unordered_map<int, int> mp;

    vector<int> s(a.begin(), a.end());
    sort(s.begin(), s.end());

    for(int i = 0; i < n; ++i) {
        mp[s[i]] = i;
    }

    for(int i = 0; i < n; ++i) { // find where elt should be in sorted array
        pos[mp[a[i]]] = mp[s[i]];
    }

    // for(int i = 0; i < n; ++i) cout << pos[i] << ' ';

    vector<vector<int>> ans;
    //ans.reserve(n);
    for(int i = 0; i < n; ++i) {
        if(vis[i + 1]) continue;
        ans.emplace_back(bfs(i));
    }
    
    cout << ans.size() << '\n';
    for(auto v : ans) {
        cout << v.size() << ' ';
        for(auto e : v) cout << e << ' ';
        cout << '\n';
    }

    return 0;
}

