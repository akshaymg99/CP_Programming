Problem link: https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1144/
Find Pivot Index


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        
        // for (int ele: nums) 
        //     sum += ele;
        
        sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int i=0; i<nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i])
                return i;
            
            leftsum += nums[i];
        }
        return -1;
        
    }
};