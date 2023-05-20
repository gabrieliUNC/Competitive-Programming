#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n+1);
        for(int i = 1; i <= n; ++i){
            prefix[i] = nums[i-1] + prefix[i-1];
        }
        set<int> s;
        for (int i = 2; i <= n; ++i){
            s.insert(prefix[i-2]%k);
            if(s.find(prefix[i]%k)!=s.end())return true;
        }
        return false;
    }
};