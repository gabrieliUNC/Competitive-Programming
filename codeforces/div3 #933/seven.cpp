#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
const int mxN = 2e5 + 8;
const ll inf = 1e18 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

template <class T> using ordered_tree = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>struct is_basic_string : std::false_type {};
template <typename CharT, typename Traits, typename Alloc>struct is_basic_string<std::basic_string<CharT, Traits, Alloc>> : std::true_type {};
template <typename T, typename = void>struct has_begin_end : std::false_type {};
template <typename T>struct has_begin_end<T, std::void_t<decltype(std::begin(std::declval<T&>())), decltype(std::end(std::declval<T&>()))>> : std::true_type {};
template <typename Tuple, std::size_t... Indices>void print_tuple_impl(std::ostream& os, const Tuple& t, std::index_sequence<Indices...>) {((os << (Indices == 0 ? "" : ", ") << std::get<Indices>(t)), ...);}
template<typename... T> ostream& operator<<(ostream& os,  const std::tuple<T...>&& v){os << "{"; print_tuple_impl(os, v, std::index_sequence_for<T...>{}); os << "}"; return os;}
template<typename... T> ostream& operator<<(ostream& os,  const std::tuple<T...>& v){os << "{"; print_tuple_impl(os, v, std::index_sequence_for<T...>{}); os << "}"; return os;}
template<typename T, typename K> ostream& operator<<(ostream& os,  const std::pair<T, K>&& v){os << "{"; os << v.first << ", " << v.second; os << "}"; return os;}
template<typename T, typename K> ostream& operator<<(ostream& os,  const std::pair<T, K>& v){os << "{"; os << v.first << ", " << v.second; os << "}"; return os;}
template<typename... T, template<class> typename C> ostream& operator<<(ostream& os,  const C<std::tuple<T...>>& v){os << "{"; if (v.size()>0) {auto en = v.end(); en = std::prev(en, 1); for (auto it = v.begin(); it != v.end(); it=std::advance(it,1)){ os << "{"; print_tuple_impl(os,*it, std::index_sequence_for<T...>{}); os << "}"; if (it != en) {os << ", ";} }} os << "}"; return os;}
template<typename... T, template<class> typename C> ostream& operator<<(ostream& os,  const C<std::tuple<T...>>&& v){os << "{"; if (v.size()>0){auto en = v.end(); en = std::prev(en, 1); for (auto it = v.begin(); it != v.end(); it=std::advance(it,1)){ os << "{"; print_tuple_impl(os,*it, std::index_sequence_for<T...>{}); os << "}"; if (it != en) {os << ", ";} }} os << "}"; return os;}
template<typename... T,template<class...> class V,typename std::enable_if<!is_basic_string<V<T...>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T...>& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<typename... T,template<class...> class V,typename std::enable_if<!is_basic_string<V<T...>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T...>&& v){os << "{";if (v.size() > 0){std::size_t en = v.size();--en; std::size_t ii = 0;for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<std::size_t XX, typename T,template<class, std::size_t> class V,typename std::enable_if<!is_basic_string<V<T, XX>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T, XX>& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<std::size_t XX, typename T,template<class, std::size_t> class V,typename std::enable_if<!is_basic_string<V<T, XX>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T, XX>&& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<typename T,template<class...> class V,typename std::enable_if<has_begin_end<V<T>>::value && !is_basic_string<V<T>>::value>::type* = nullptr>std::istream& operator>>(std::istream& is, V<T>& v) {for (auto it = std::begin(v); it != std::end(v); ++it) {is >> *it;}return is;}

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

struct Fen {
    vector<ll> bit;  // binary indexed tree
    int n;

    Fen(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0LL);
    }


    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void range_add(int l, int r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }

};


vector<int> dist;
vector<vector<pair<int, int>>> g;
using node = array<int, 3>;

int solve(int src, int dest) {
    /*
    
    <cost, cur color, node>
    
    */
    dist.assign(mxN, (int)2e5 + 1);
    auto comp = [&] (const node& a, const node& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    };
    priority_queue<node, vector<node>, decltype(comp)> pq(comp);
    dist[src] = 0;
    pq.push({0, -1, src});

    while(pq.size()) {
        auto [cost, color, u] = pq.top(); pq.pop();
        cout << u << ' ' << cost << '\n';
        // if(dist[u] != cost) continue;

        for(auto& [other_color, v] : g[u]) {
            if(u == v) continue;
            // cout << u << ' ' << v << '\n';
            int d = (color == other_color ? 0 : 1);
            // cout << cost << '\n';

            if(cost + d < dist[v]) {
                dist[v] = cost + d;
                pq.push({cost + d, other_color, v});
            }
        }

    }
    
    return dist[dest];
}

int main(){
    START
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        g.clear();
        g.resize(n);

        for(int i = 0; i < m; ++i) {
            int u, v, color; cin >> u >> v >> color;
            --u; --v;
            // cout << u << ' ' << v << '\n';
            g[u].push_back({color, v});
            g[v].push_back({color, u});
        }

        // for(int i = 0; i < n; ++i) {
        //     for(auto node : g[i]) cout << i << ' ' << node.S << '\n';
        // }

        int src, dest; cin >> src >> dest;
        --dest; --src;

        cout << solve(src, dest) << '\n';
        
    }



    return 0;
}

                                 