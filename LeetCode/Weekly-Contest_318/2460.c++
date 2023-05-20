#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i+1<nums.size(); ++i){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]= 0;
            }
        }
        int size = 0;
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
            else{
                size++;
            }
        }
        for(int i=0; i<size; ++i){
            ans.push_back(0);
        }
            
    return ans;
    }
};