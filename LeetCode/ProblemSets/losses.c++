#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int>first;
        vector<int>second;
        map<int, int> winners, losers;
        for(auto list: matches){
            winners[list[0]]++;
            losers[list[1]]++;
        }
        for(pair<int, int> e: winners){
            if(losers.count(e.first)==0){
                first.push_back(e.first);
            }
        }
        for(pair<int, int>e : losers){
            if(e.second==1){
                second.push_back(e.first);
            }
        }
        ans.push_back(first); ans.push_back(second);
        return ans;
        
    }
};