#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define sz(x) (int)x.size()
template<typename FUNCTION>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define loopd(x, n) for(int x = n; x>=0; --x)
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define START ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                                                            
#define CPU cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#define vi vector<int>;
#define vvi vector<vi>;
#define pii pair<int, int>;
#define vpii vector<pii>;

const int MOD = 1e9 + 7;
const ll inf = 1e18 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = 1e18;  // Will overflow if T is an int

	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
		}
	}

	/** @return the op element in the range [start, end) */
	T range_min(int start, int end) {
		T op = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { op = std::min(op, segtree[start++]); }
			if (end % 2 == 1) { op = std::min(op, segtree[--end]); }
		}
		return op;
	}
};

int main(){
    START
    
    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < m; ++i){
            int u, v, w; cin >> u >> v >> w;
            --u; --v;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> s(n);
        for(auto &e : s) cin >> e;

        priority_queue<array<ll, 3>> pq;
        vector<vector<ll>> dist(n, vector<ll>(1001, 1e18));
        vector<vector<bool>> v(n, vector<bool>(1001, 0));

        dist[0][s[0]] = 0;
        pq.push({0, 0, s[0]});

        while(pq.size()){
            int u = pq.top()[1], k = pq.top()[2];
            pq.pop();

            if(v[u][k] || dist[u][k] == 1e18) continue;
            v[u][k] = 1;

            for(auto x : adj[u]){
                int v = x.first, w = x.second;
                int c = min(s[v], k);

                if(dist[v][c] > dist[u][k] + 1LL * w * k){
                    dist[v][c] = dist[u][k] + 1LL * w * k;
                    pq.push({-dist[v][c], v, c});
                }
            }
        }

        ll ans = 1e18;

        for(int k = 1; k <= 1000; ++k) ans = min(ans, dist[n - 1][k]);
        cout << ans << '\n';
    }



    return 0;
}

                                 
