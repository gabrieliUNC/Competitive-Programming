#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, curr[101][101], l[101], r[101], ans[101][101];
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) for(int j = 1;j <= m; ++j) cin >> curr[i][j];
		for(int i = 1; i <= n; ++i) sort(curr[i] + 1,curr[i] + m + 1), l[i] = 1, r[i] = m;
		for(int i = 1; i <= m; ++i){
			ll low=1e9+7, high=0;

			for(int j = 1; j <= n; ++j) if(curr[j][l[j]] < low) low = curr[j][l[j]], high=j;

			for(int j = 1; j <= n; j++){
				if(high == j) ans[i][j] = curr[j][l[j]++];
				else ans[i][j] = curr[j][r[j]--];
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1 ; j <= m ; ++j) cout << ans[j][i] << ' ';
			cout << '\n';
		}
	}
}
