#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int n, rem = 0, add = 0; ll c, d;
        cin >> n >> c >> d;

        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        int sz = *max_element(a.begin(), a.end());
        set<int> u (a.begin(), a.end());
        int unique = u.size();

        rem = n - unique;

        ll ans = 0;

        set<int> v;

        int i = 1;
        for(int e : u){
            if(i != e){
                v.insert(i);
            }

            ans = min(ans, (ll)((c * v.size()) + (d * (unique - i))));

            ++i;
        }

        ans += (rem * c);
        
        cout << ans << '\n';

    }



    return 0;
}