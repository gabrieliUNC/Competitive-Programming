#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll p, y; cin >> p >> y;
    bool ok = false;
    ll i;
    for(i = y; i > p; --i){

        ok = true;
        for(ll j = 2; j <= p; ++j){
            if(j * j > i)break;
            if(i % j == 0){ok = false; break; }
        }
        if(ok)break;
    }

    if(ok)cout << i << '\n';
    else cout << -1 << '\n';

    return 0;
}