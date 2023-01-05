#include <bits/stdc++.h>
using namespace std;


struct Fen {
	vector<long long> tt;
	int n;
	void init(int nn) {
		n = nn	+ 2;
		tt.resize(nn + 3, 0LL);
	}
	
	void upd(int i, long long v) {
		while (i <= n) {
			tt[i] += v;
			i += i & -i;
		}
	}
	
	long long get(int i) {
		long long ss = 0;
		while (i > 0) {
			ss += tt[i];
			i -= i & -i;
		}
		return ss;
	}
};