/*
Problem link: https://leetcode.com/problems/move-zeroes/
Move zeros to the end of array
*/

//Apporach 1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        for(int fast=0; fast<nums.size(); ++fast) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        
        for (int i=slow; i<nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

// Approach 2

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastpos = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[lastpos++], nums[i]);
            }
        }
    }
};