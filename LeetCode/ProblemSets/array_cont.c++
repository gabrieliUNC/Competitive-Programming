#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        set<int> s;
        for(int i = 0; i < n; ++i)s.insert(nums[i]);
        vector<int> a(s.begin(), s.end());
        for(int N = a.size(); j < N; ++j){
            while(a[i] + n <= a[j]) ++i;
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};