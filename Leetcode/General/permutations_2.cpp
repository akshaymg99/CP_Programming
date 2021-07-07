/*
Problem link: 
Permuation while there are duplicate elements
*/

// Using next_permutation STL

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int>> output;
        
        output.emplace_back(nums);
        while(next_permutation(nums.begin(), nums.end())) {
            output.emplace_back(nums);
        }   
        return output;
    }
};