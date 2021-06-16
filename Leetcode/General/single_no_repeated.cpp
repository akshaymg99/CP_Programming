/*
Problem link: https://leetcode.com/problems/single-number
Finding single repeated number
*/

//Using Hash map

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for (auto num:nums) {
            myMap[num] ++; 
        }
        
        for (auto it: myMap) {
            if (it.second == 1)
                return it.first;
        }
        return 0;
    }
};

// Using XOR Operation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto num: nums) {
            x = x ^ num; 
        }
        return x;
    }
};


// Using Math (Python)
// 2 * (a+b+c) - (a+a+b+b+c) = c

class Solution(object):
    def singleNumber(self, nums):
        return 2 * sum(set(nums)) - sum(nums)

