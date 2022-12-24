#include <bits/stdc++.h>
using namespace std;
#define ll long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<ll> ans;
        ll i = 1;
        ll k = sqrtl(n);
        for(int i=0; i<=k; ++i){
            ans.insert(i);
            if(i!=0){
                ans.insert(n/i);
            }
        }

        cout << ans.size() << '\n';
        for (auto e: ans){
            cout << e << " ";
        }
        cout << '\n';
    }



    return 0;
}