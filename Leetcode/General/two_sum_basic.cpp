/*
Problem link: https://leetcode.com/problems/two-sum/
Two sum with hash map O(n) runtime 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
        vector <int> ans;
        
        for (int i=0; i<nums.size(); ++i) {
            int no = target - nums[i];
            
            if (hash.find(no) != hash.end()) {
                ans.push_back(hash[no]);
                ans.push_back(i);
                return ans;
            }
            
            hash[nums[i]] = i;
        }
        
        return ans;
        
    }
};