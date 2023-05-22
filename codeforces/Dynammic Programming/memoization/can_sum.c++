#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 8;
ll memo[N];


bool can_sum(ll target, vector<ll> nums){
    if(memo[target] != -1) return memo[target];
    if(target == 0) return true;
    if(target < 0) return false;

    for(ll e: nums){
        if(can_sum(target - e, nums)){
            memo[target] = 1;
            return true;
        }
    }

    memo[target] = 0;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < N; ++i) memo[i] = -1;

    ll n, target; cin >> n >> target;
    vector<ll> a;

    for(int i = 0; i < n; ++i){
        ll e; cin >> e;
        a.push_back(e);
    }
    
    cout << boolalpha;
    cout << can_sum(target, a) << '\n';


    return 0;
}