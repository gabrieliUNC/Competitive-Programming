#include <bits/stdc++.h>
#define ll long long
using namespace std;

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

	/** @return the minimum element in the range [start, end) */
	T range_min(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum = std::min(sum, segtree[start++]); }
			if (end % 2 == 1) { sum = std::min(sum, segtree[--end]); }
		}
		return sum;
	}
};

int main(){
    int n, q; cin >> n >> q;
    MinSegmentTree<ll> t(n);
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        t.set(i, a);
    }

    for(int i = 0; i < q; ++i){
        int a, b, c; cin >> a >> b >> c;
        if(a == 2){
            cout << t.range_min(b - 1, c) << '\n';
        } else{
            t.set(b - 1, c);
        }
    }



    return 0;
}