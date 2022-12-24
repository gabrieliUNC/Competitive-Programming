#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 1;
set<int> friends[mxN];
bool dead[mxN];

int alive = 0;

void update(int st) {
    if (dead[st] && ((friends[st].size() && *begin(friends[st]) < st) || !friends[st].size())) {
        dead[st] = false;
        ++alive;
    }
    if (friends[st].size() && *begin(friends[st]) > st) {
        if (!dead[st]) {
            alive--;
        }
        dead[st] = true;
        for (const auto& frin : cpy) {
            update(frin);
        }
    }
}
void updateAdd(int st, int toAdd) {
    friends[st].insert(toAdd);
    friends[toAdd].insert(st);
    update(st);
    update(toAdd);
}
void updateRemove(int st, int toAdd) {
    friends[st].erase(toAdd);
    friends[toAdd].erase(st);
    update(st);
    update(toAdd);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    alive = n;
    fill(dead, dead + n + 1, false);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        friends[v].insert(u);
        friends[u].insert(v);
    }
    for (int i = 1; i <= n; ++i) {
        update(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << (dead[i] ? "yes" : "no") << '\n'; 
    }
    int q; cin >> q;
    while (q --> 0) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            updateAdd(u, v);
        } else if (t == 2) {
            int u, v; cin >> u >> v;
            updateRemove(u, v);
        } else {
            //3
            cout << "=============";
            cout << alive << '\n';
            cout << "========\n";
        }
    }
}