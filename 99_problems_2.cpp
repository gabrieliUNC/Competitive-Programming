#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int tmp; cin >> tmp;
        mp[tmp]++;
    }

    for(int i = 0; i < q; ++i){
        int T, discard_value; cin >> T >> discard_value; // Query Type and Desired Val

        if(T == 1) { // Remove smallest value > Val 
            if(mp.empty()){
                cout << -1 << '\n';
                continue;
            }

            auto ptr = mp.upper_bound(discard_value); // Remove smallest val > Val
            if(ptr == mp.end()) --ptr; // Might only have vals > Val

            auto [num, cnt] = *ptr; // find target
            if(num > discard_value && cnt != 0) { // validate
                cout << num << '\n';
                mp[num]--;
                if(mp[num] == 0) mp.erase(num); // prune missing vals
            } else {
                cout << -1 << '\n';
            }
        } else {
            if(mp.empty()){
                cout << -1 << '\n';
                continue;
            }

            auto ptr = mp.upper_bound(discard_value); // Remove greatest val <= Val
            if(ptr != mp.begin()) --ptr; // Might only have vals < Val
            auto [num, cnt] = *ptr;
            if(num <= discard_value && cnt != 0){
                cout << num << '\n';
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
            } else{
                cout << -1 << '\n';
            }
        }
    }

    // put everything in tree map to b-s for vals

    /**
     * @brief 
     * T = 1
     *  Find easiest problem harder then D
     *  upper_bound
     *  check res is > D 
     * 
     * T = 2
     *  Find hardest problem not harder then D
     *  lower_bound
     *  check res is <= D
     */
    




    return 0;
}