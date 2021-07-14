/*
Problem link: https://leetcode.com/problems/missing-number/
Find missing number in consecutive array
*/

// Using summation formula

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

// Using Bit manipulation (XOR)

class Solution:
    def missingNumber(self, nums):
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

