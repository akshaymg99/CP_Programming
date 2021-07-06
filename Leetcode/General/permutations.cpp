/*
Problem link: https://leetcode.com/problems/permutations/
Permutations of given integers by backtracking
*/

class Solution {
private:
    vector< vector<int>> res;   
    void permutations(vector<int>&nums, int l, int r) {
        if (l == r-1)
            res.push_back(nums);
        else {
            for (int i=l; i<r; ++i) {
                swap(nums[i], nums[l]);
                permutations(nums, l+1, r);
                swap(nums[i], nums[l]);
            }
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        permutations(nums, 0, n);
        return res;
    }
};