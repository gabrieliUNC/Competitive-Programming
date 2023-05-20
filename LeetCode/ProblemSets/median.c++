#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<float> merged;
        for(int e: nums1) merged.push_back((float)e);
        for(int e: nums2) merged.push_back((float)e);
        sort(merged.begin(), merged.end());
        if (merged.size()%2==0){
            return (((merged[(merged.size()-1)/2]) + (merged[((merged.size()-1)/2)+1]))/2);
        }
        else{
            return merged[merged.size()/2];
        }
        
    }
};