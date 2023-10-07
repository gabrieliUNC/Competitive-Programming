#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll amount, max_amt, max_pills; cin >> amount >> max_amt >> max_pills;
    set<ll> ans;
    ll high = sqrt(max_amt) + 1e7;

    for(ll pico = 1; pico <= high; ++pico){
        if(!(amount % pico)){
            if(ceil(amount / pico) <= max_pills && pico <= max_amt) ans.insert(pico);
            if(pico <= max_pills && ceil(amount / pico) <= max_amt) ans.insert(amount / pico);
        }
    }

    cout << ans.size() << '\n';
    if(ans.size())
        for(auto num : ans) cout << num << '\n';

    return 0;
}