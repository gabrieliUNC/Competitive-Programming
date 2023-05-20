#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int, vector<int>> memo;
vector<int> check;
vector<int> how;
vector<int> best_ans;


vector<int> how_sum(ll target, vector<ll> nums){
    if(memo.count(target)) return memo[target];
    if(target == 0){
        memo[target] = how;
        return memo[target];
    }
    if(target < 0){
        memo[target] = check;
        return check;
    }

    for(ll e: nums){
        vector<int> ans = how_sum(target - e, nums);
        if(check != ans){
            ans.push_back(e);
            memo[target] = ans;
            if(memo[target].size() < best_ans.size()){
                best_ans = memo[target];
            }
        }
    }
    

    if(best_ans != check) return best_ans;

    return check;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, target; cin >> n >> target;
    vector<ll> a;
    best_ans = check;

    check.clear();
    check.push_back(-1);

    how.clear();

    for(int i = 0; i < n; ++i){
        ll e; cin >> e;
        a.push_back(e);
    }
    
    vector<int> ans = how_sum(target, a);

    for(int e: ans) cout << e << ' ';
    cout << '\n';



    return 0;
}