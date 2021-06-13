/*
Problem link: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1301/
Max counsecutive ones in an array
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == 1) 
                count ++;
            
            else if (nums[i] == 0) 
                count = 0;
            
            ans = max(ans, count);
            
        }
        return ans;
    }
};