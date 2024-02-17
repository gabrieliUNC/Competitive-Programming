#include <bits/stdc++.h>
using namespace std;

int inf = 1e9 + 7;

int main(){ 
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    sort(a.begin(), a.end());
    

    int ans = INT_MAX, hi = *max_element(a.begin(), a.end());

    for(int i = 0; i <= hi; ++i){
        auto it = lower_bound(a.begin(), a.end(), i);
        int dist = distance(a.begin(), it);
        if(dist == n || dist == 0) ans = min(ans, n);
        else ans = min(ans, i + n - dist - 1);
    }

    cout << ans << '\n';



    return 0;
}