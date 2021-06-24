/*
Problem link: https://leetcode.com/problems/longest-consecutive-sequence
Longest consecutive sequence in an unsorted array
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_streak = 0;
        set <int> bounds(nums.begin(), nums.end());
        int current_streak = 0;
        
        
        for (auto& num: nums) {
            if (bounds.find((num-1)) == bounds.end() ) {
                int current_num = num;
                current_streak = 1;
                
                while (bounds.find(current_num+1) != bounds.end()) {
                    current_num ++;
                    current_streak++ ;
                }
                longest_streak = max(longest_streak, current_streak);
            }
        }
        
        return longest_streak;
        
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int longest_streak = 1;
        int current_streak = 1;
        
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1]+1)
                    current_streak ++;    
                else {
                    longest_streak = max(longest_streak, current_streak);
                    current_streak = 1;
                }
            }
                
        }
        
        return max(longest_streak, current_streak);
        
    }
};