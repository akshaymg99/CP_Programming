/*
Problem link: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1151/
Remove elements in array in-place 
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
        
    }
};