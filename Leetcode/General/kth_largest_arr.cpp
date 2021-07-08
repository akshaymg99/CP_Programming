/*
Problem link: https://leetcode.com/problems/kth-largest-element-in-an-array
Kth largest element in an array
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> pq(nums.begin(), nums.end());
        
       for (int i=0; i<k-1; ++i) {
           pq.pop();
       } 
        
       return pq.top();
    }
};

// STL nth element

int findKthLargest(vector<int>& nums, int k) {
	nth_element(nums.begin(), nums.begin()+nums.size()-k, nums.end());
	return nums[nums.size()-k];
}

