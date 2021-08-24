/*
Problem link: https://leetcode.com/problems/binary-search
Binary search for a sorted array
*/

// Recursive approach

class Solution {
private:
    int bin_search(vector<int>&nums, int low, int high, int target) {
        
        if (low <= high) {
            int mid = low + (high-low)/2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                return bin_search(nums, low, mid-1, target);
            else if (nums[mid] < target)
                return bin_search(nums, mid+1, high, target);
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return bin_search(nums, 0, nums.size()-1, target);
    }
};

// Iterative Approach

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        
        while (left <= right) {
            
            mid = left + (right - left)/2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid+1;
            else if (nums[mid] > target)
                right = mid-1;
        }
        
        return -1;
    }
};