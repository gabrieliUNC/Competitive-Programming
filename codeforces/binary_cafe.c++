#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;

    while(tt--){
        ll n, k; cin >> n >> k;

        if(k > 34) cout << n + 1 << '\n';

        else cout << min(n + 1, 1LL << k) << '\n';
    }




    return 0;
}