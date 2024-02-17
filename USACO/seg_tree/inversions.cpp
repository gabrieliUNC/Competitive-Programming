#include <bits/stdc++.h>
#define ll long long
using namespace std;


template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = 0;  // Will overflow if T is an int

	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}

	/** @return the op element in the range [start, end) */
	T range_sum(int start, int end) {
		T op = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { op += segtree[start++]; }
			if (end % 2 == 1) { op += segtree[--end]; }
		}
		return op;
	}
};

int main(){
    int n; cin >> n;
    vector<int> a(n), p(n, 0);
    for(auto &e : a) cin >> e;
    MinSegmentTree<ll> seg(n);

    for(int i = 0; i < n; ++i){
        p[i] = seg.range_sum(a[i] - 1, n);
        seg.set(a[i] - 1, 1);
    }

    for(auto e : p) cout << e << ' ';
    cout << '\n';



    return 0;
}