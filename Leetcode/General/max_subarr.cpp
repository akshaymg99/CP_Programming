/*
Problem link: https://leetcode.com/problems/maximum-subarray/
Maximum contiguous sub array sum 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sub = nums[0], max_sub = nums[0];
        
        for (int i=1; i<nums.size(); ++i) {
            cur_sub = max(nums[i], cur_sub + nums[i]);
            
            max_sub = max(cur_sub, max_sub);
        }
        return max_sub;
    }
};