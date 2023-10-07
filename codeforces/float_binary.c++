#include <bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int n, p; cin >> n >> p;
    vector<pair<ld, int>> a(n);
    for(int i = 0; i < n; ++i){
        int t1, t2; cin >> t1 >> t2;
        a[i].first = (ld)t1 / (ld) p, a[i].second = t2;
    }

    ld l = 0.0, r = 1e9, mid;

    for(int i = 0; i < 100; ++i){
        mid = (ld)((l + r) / 2.0);

        bool ok = 1;
        ld food = 0.0;
        unordered_map<int, int> mp;

        for(int j = 0; j < n; ++j){
            int curr = a[j].first, expires = a[j].second;
            food += curr;

            if(curr) mp[j + expires] += curr;
            if(mp.count(j)) food -= mp[j];

            if(food < mid){
                ok = 0;
                break;
            }

        }

        if(ok) l = mid;
        else r = mid;
    }

    if(mid < 0.00000001) cout << -1 << '\n';
    else cout << mid << '\n';


    return 0;
}