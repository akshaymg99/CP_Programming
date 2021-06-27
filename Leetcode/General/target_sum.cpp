/*
Problem link: https://leetcode.com/problems/target-sum
Find no of ways the target sum can be achieved with given numbers by addition and subtraction operation
*/

class Solution {
private:
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        calculate(nums, 0, 0, target);
        return count;
    }
    void calculate(vector<int>&nums, int i, int sum,int target) {
        if (i == nums.size()) {
            if (sum == target)
                count ++;
        }
        else {
            calculate(nums, i+1, sum + nums[i], target);
            calculate(nums, i+1, sum - nums[i], target);
        }
    }
};