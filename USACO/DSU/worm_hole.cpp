#include <bits/stdc++.h>
using namespace std;


struct DSU{
    vector<int> e;
    DSU(int N): e(N, -1) {};
    int get(int x){ return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int x, int y) {return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool uni(int x, int y){
        x = get(x), y = get(y);
        if(x == y) return 0;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    int n, m; cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i]--;
        if(a[i] != i) mp[i]++;
    }

    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; ++i){
        int weight, u, v; cin >> u >> v >> weight;
        u--;
        v--;
        edges.push_back({weight, {u, v}});
    }

    if(!mp.size()){
        cout << -1 << '\n';
        return 0;
    }

    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    DSU dsu(n);

    for(int edge = 0; edge < m; ++edge){
        int weight = edges[edge].first, u = edges[edge].second.first, v = edges[edge].second.second;
        dsu.uni(u, v);

        int par = dsu.get(mp.begin()->first);
        bool ok = 1;
        for(auto it = ++mp.begin(); it != mp.end(); ++it){
            if(dsu.get(it->first) != par){
                ok = 0;
                break;
            }
        }
        if(ok) {
            cout << weight << '\n';
            break;
        }
    }



    return 0;
}