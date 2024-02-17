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