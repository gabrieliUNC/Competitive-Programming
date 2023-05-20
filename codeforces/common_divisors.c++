#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

    int n; cin >> n;
    ll factor;

    for(int i = 0; i < n; ++i){
        ll elt; cin >> elt;
        if(!i) factor = elt;
        else factor = gcd(factor, elt);
    }


    ll cnt = 0;

    if(factor == 1){
        std::cout << factor << '\n';
        return 0;
    }

    for (ll i = 1; i * i <= factor; ++i){ 
        if(factor % i == 0 && i * i != factor) cnt += 2;
        if(factor % i == 0 && i * i == factor) cnt++;
    }

    std::cout << cnt << '\n';

    return 0;
}