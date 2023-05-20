#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[10005];

signed main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k, ans = -1e9 + 6; cin >> n >> k;

	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int l = 1; l <= n; ++l){

		for(int r = l; r <= n; ++r){

			multiset <int> s1,s2;

			int s = 0;

			for(int k = l; k <= r; ++k) s1.insert(a[k]),s+=a[k];

			for(int k = 1; k < l; ++k) s2.insert(a[k]);

			for(int k = r + 1; k <= n; ++k) s2.insert(a[k]);

			ans = max(ans , s);

			for(int i = 1; i <= k; ++i){
				s -= *s1.begin();
				s2.insert(*s1.begin());
				s1.erase(s1.begin());
				s += (*(--s2.end()));
				s1.insert(*(--s2.end()));
				s2.erase((--s2.end()));
				ans = max(ans , s);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}