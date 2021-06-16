/*
Problem link: https://leetcode.com/problems/intersection-of-two-arrays
Intersection operation of two arrays
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> set1 (nums1.begin(), nums1.end());
        unordered_set <int> set2 (nums2.begin(), nums2.end()); 
        vector <int> ans;
        
        int size1 = set1.size();
        int size2 = set2.size();
        
        if (size1 > size2) {
            for (auto it: set2) {
                if (set1.find(it) != set1.end())
                    ans.push_back(it);
            }
        }
        else {
            for (auto it: set1) {
                if (set2.find(it) != set2.end())
                    ans.push_back(it);
            }
            
        }
        return ans;
        
    }
};