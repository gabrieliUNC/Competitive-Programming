#include <bits/stdc++.h>
#define ll long long
using namespace std;


main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    map<ll, ll> m;
    ll max_t = 0;
    ll min_t = INT_MAX;
    for(int i=0; i<n; i++){
        ll temp; cin >> temp;
        min_t = min(min_t, temp);
        max_t = max(max_t, temp);
        m[temp]++;
    }
    ll dif = max_t - min_t;

    ll ans = max_t==min_t && n==2 ? 1: m[max_t] * m[min_t];
    

    cout << dif << " " << ans << "\n";


    return 0;
}