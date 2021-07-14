/*
Problem link: https://leetcode.com/problems/missing-number/
Find missing number in consecutive array
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_ele =  *max_element(nums.begin(), nums.end());
        if (n != max_ele)
            return n;
        return max_ele*(max_ele+1)/2 - sum;
    }
};