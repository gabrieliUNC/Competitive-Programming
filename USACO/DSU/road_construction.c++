#include <bits/stdc++.h>
using namespace std;


const int mxN = 2e5 + 7;

int dsu[mxN];
int sz[mxN];

int find(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}

bool uni(int x, int y){
    x = find(x), y = find(y);

    if (x == y) return false;

    if (sz[y] < sz[x]) swap(x, y);

    dsu[x] = dsu[y];
    sz[y] += sz[x];

    return true;
}


int main(){
    int n, m; cin >> n >> m;
    int largest = 1, indp = n;

    for(int i = 1; i <= n; ++i) dsu[i] = i, sz[i] = 1;

    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        if(uni(x, y)) indp--;
        largest = max(sz[find(x)], largest);

        cout << indp << ' ' << largest << '\n';
    }
}