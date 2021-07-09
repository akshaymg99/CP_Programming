/*
Problem link: https://leetcode.com/problems/kth-largest-element-in-an-array
Kth largest element in an array
*/

// Priority queue as MAX HEAP

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

// With Partial sort

int findKthLargest(vector<int>& nums, int k) {
	partial_sort(nums.begin(), nums.begin()+nums.size()-k+1, nums.end());
	return nums[nums.size()-k];
}

// Max Heap using multiset

int findKthLargest(vector<int>& nums, int k) {
	multiset<int, greater<int>> mst(nums.begin(),nums.end());

	for(int i=1; i<k; ++i) 
		mst.erase(mst.begin());
	
	return *mst.begin();
}