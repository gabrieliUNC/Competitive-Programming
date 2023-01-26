#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        ll ans = x;
        if(x == y) { cout << x << '\n'; continue; }
        ll res = x;
        bool ok = false;
        while(res){
            x += (x & -x);
            res &= x;
            if(res==y){ cout << x << '\n'; ok = true; break;}
        }

        if(!ok)cout << -1 << '\n';
    }




    return 0;
}