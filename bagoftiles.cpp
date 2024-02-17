#include <bits/stdc++.h>
#define ll long long
using namespace std;


unordered_map<ll, __int128_t> mp;
__int128_t factorial(long long n){
    if(n <= 1) return mp[n] = 1;
    if(mp.find(n) != mp.end()) return mp[n];
    return mp[n] = n * factorial(n - 1);
}


pair<long long, __int128_t> solve(){
    int num_tiles; cin >> num_tiles;
    vector<int> tiles(num_tiles);
    for(auto &e : tiles) cin >> e;


    int num_chosen, target; cin >> num_chosen >> target;
    //int num_chosen, target; cin >> target >> num_chosen;

   
    if(num_chosen == 0) 
     {
         if (target == 0)
             return {1, 1};
         return {0, 1};
     }
     if (num_tiles == 0) {
        //implies num_chosen == 0
        return {1, 1};
     }


    map<pair<ll, ll>, vector<int>> left, right;
    
    for(int i = 1; i < (1 << (num_tiles / 2)); ++i) {
        if(__builtin_popcount(i) <= num_chosen) {
            int sum = 0;
            for(int j = 0; j < (num_tiles / 2); ++j) if (i & (1 << j)) {
                //we can take j
                // cout << j << '\n';
                sum += tiles[j];
            }
            if (sum != 0)
            left[{sum, __builtin_popcount(i)}].push_back(i);
        }
    }

    for(int i = 1; i < (1 << ((num_tiles+1) / 2)); ++i) {
        if(__builtin_popcount(i) <= num_chosen) {
            int sum = 0;
            for(int j = 0; j < ((num_tiles+1)/2); ++j) if (i & (1 << j)) {
                //we can take j
                sum += tiles[j + (num_tiles/2)];
            }
            if (sum != 0)
            right[{sum, __builtin_popcount(i)}].push_back(i << (num_tiles/2));
        }
    }
    
    long long correct = left[{target, num_chosen}].size() + right[{target, num_chosen}].size();
    for(auto& [p, cnt] : left) {
        auto [num, sz] = p;
        pair<ll, ll> complement{target-num, num_chosen - sz};
        
        if(right.count(complement)){
            correct += (cnt.size() * 1LL * right[complement].size());
        }
                        
    }


    long long total = (factorial(num_tiles) / (factorial(num_chosen) * factorial(num_tiles - num_chosen)));
    return { correct, total };


}




int main(){
    int tt; cin >> tt;
    for(int i = 1; i <= tt; ++i) {
        auto [correct, total] = solve();

        cout << "Game " << i << " -- " << correct << " : " << total - correct << '\n';

    }



    return 0;
}