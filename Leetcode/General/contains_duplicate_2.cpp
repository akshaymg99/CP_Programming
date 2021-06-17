/*
Problem link: https://leetcode.com/problems/contains-duplicate-ii/
Find two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        
        for (int i=0; i<nums.size(); ++i) {
            if (map.count(nums[i])) {
                int diff = abs(map[nums[i]] - i);
                if (diff <= k)
                    return true;
            }
            
            map[nums[i]] = i;
        }
        return false;
        
    }
};