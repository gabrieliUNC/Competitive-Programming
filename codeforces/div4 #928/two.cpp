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
const int mxN = 1e7 + 8;
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

bool primes[mxN];
int len, sp[mxN];

void Sieve(){
	for (int i = 2; i < mxN; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < mxN; i += 2){
		if (!primes[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < mxN; j += 2){
				if (!primes[j*i])	primes[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

vector <int> factorize(int k) {
	vector <int> ans;
	while(k > 1) {
		ans.push_back(sp[k]);
		k /= sp[k];
	}
	return ans;
}

struct DSU {
	vector<int> e;
	DSU(int N) : e(N, -1) {}

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	// union by size
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
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

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


vector<int> LPS(string pat)
{
    int n = pat.size();
    // length of the previous longest prefix suffix
    
    int len = 0;
    vector<int> lps(n, 0);
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    auto lps = LPS(pat);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}


int main(){
    START
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }


        if(sum % 3 == 0) cout << 0 << '\n';
        else if(sum % 3 == 2 || (sum + 1) % 3 == 0) cout << 1 << '\n';
        else {
            bool ok = 0;
            for(int i = 0; i < n; ++i) {
                if((sum - a[i]) % 3 == 0) ok = 1;
            }
            cout << (ok ? 1 : 2) << '\n';
        }
        
        
    }



    return 0;
}

                                 
