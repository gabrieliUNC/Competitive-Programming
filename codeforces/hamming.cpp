#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, hamming = 0, ans = 0, best_i = -1, best_j = -1, sz = 0; cin >> n;
    string s, t; cin >> s >> t;
    unordered_map<char, vector<int>> mp;


    //find points of replacement
    for(int i = 0; i < n; ++i){
        if(s[i] != t[i]){
            ++hamming;
            mp[t[i]].push_back(i);     
            ++sz;  
        }
    }

    //try replacement
    for(int i = 0; i < n; ++i){
        if(mp.count(s[i])){
                for(auto idx : mp[s[i]]){ //check replacement positions
                    if(i == idx) continue;
                    if(s[idx] == t[i] && s[idx] != t[idx] && s[i] != t[i]) {
                        ans = 2;
                        best_i = idx;
                        best_j = i;
                    }
                    else if (s[idx] != t[idx] && s[i] != t[i] && !ans){
                        ans = 1;
                        best_i = idx;
                        best_j = i;
                    }
                }
                if(sz > 5e2) { sz -= mp[s[i]].size(); mp.erase(s[i]); }
            }
    }

    cout << (hamming - ans) << '\n';
    cout << (best_i == -1 ? best_i : best_i + 1) << ' ' << (best_j == -1 ? best_j : best_j + 1) << '\n';


    return 0;
}