/*
Problem link: https://leetcode.com/problems/rotate-array/
Rotate Array by k linearly
*/

//Using reverse method

class Solution {
public:
    void rev(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start ++;
            end --;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        //reverse(nums.begin(), nums.end());
        //reverse(nums.begin(), nums.begin() + k);
        //reverse(nums.begin() + k, nums.end());

        rev(nums, 0, n-1);
        rev(nums, 0, k-1);
        rev(nums, k, n-1);
        
    }
};