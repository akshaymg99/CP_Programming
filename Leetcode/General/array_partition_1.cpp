Problem link: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1154/
Array Partition 1

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for (auto i=nums.begin(); i<nums.end(); i=i+2) {
            sum += min(*i, *i+1);
        }
        
        return sum;
        
    }
};