/*
Problem link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
Intersection of two arrays 2
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>:: iterator it;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin());
        nums1.erase(it, nums1.end());
        return nums1;
    }
};