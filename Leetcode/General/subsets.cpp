/*
Generating all subsets of given array
*/

// Bit manipulation - Binary enumeration

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int>> ans;
        int n = nums.size();
        int num = pow(2, n);
        int i=0;
        
        while(i< num) {
            vector<int> temp;
            
            for (int j=0; j<n; ++j) {
                if (i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            ++i;
        }
        return ans;
    }
};