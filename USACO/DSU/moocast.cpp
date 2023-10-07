#include<bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) : e(N, -1) {}

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

struct Edge {
	int a, b, dist;
};

int main() {
	int n; cin >> n;
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);

	vector<int> x(n), y(n);

	for (int i = 0; i < n; i++) cin >> x[i] >> y[i]; 

	vector<Edge> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			edges.push_back({i, j, dx * dx + dy * dy});
		}
	}

	auto cmp = [](const Edge &e1, const Edge &e2) { return e1.dist < e2.dist; };
	std::sort(edges.begin(), edges.end(), cmp);

	
	int ans = 0;
	int comp_num = n;
	DSU dsu(n);
	for (const Edge &e : edges) {
		if (dsu.unite(e.a, e.b)) {
			ans = e.dist;
			if (--comp_num == 1) { break; }
		}
	}

    cout << ans << '\n';

    return 0;
}