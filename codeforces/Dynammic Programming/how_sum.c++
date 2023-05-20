#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int, vector<int>> memo;


vector<int> how_sum(ll target, vector<ll> nums){
    if(memo.count(target)) return memo[target];
    if(target == 0){
        vector<int> how;
        how.clear();
        memo[target] = how;
        return memo[target];
    }
    if(target < 0){
        vector<int> how;
        how.clear();
        how.push_back(-1);
        memo[target] = how;
        return how;
    }

    for(ll e: nums){
        vector<int> check; check.clear();
        check.push_back(-1);
        vector<int> ans = how_sum(target - e, nums);
        if(check != ans){
            ans.push_back(e);
            memo[target] = ans;
            return memo[target];
        }
    }

    vector<int> check; check.clear();
    check.push_back(-1);

    memo[target] = check;

    return check;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, target; cin >> n >> target;
    vector<ll> a;

    for(int i = 0; i < n; ++i){
        ll e; cin >> e;
        a.push_back(e);
    }

    sort(a.begin(), a.end(), greater<int>());
    
    vector<int> ans = how_sum(target, a);

    for(int e: ans) cout << e << ' ';
    cout << '\n';


    return 0;
}