Problem Link: https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/
Largest Number At Least Twice of Others

#include <bits/stdc++.h>

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max_ele = *max_element(nums.begin(), nums.end());
        auto it = find(nums.begin(), nums.end(), max_ele);
        int index = it - nums.begin();
        
        for (int i=0; i<nums.size(); ++i) {
            if (2*nums[i] > max_ele && i!=index) {
                return -1;
            }
        }
        return index;
        
    }
};