// Problem link: https://leetcode.com/problems/two-sum/ 
// Finding indices of two numbers in an array that sum upto target no 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        
        unordered_map<int, int> mymap;
        for(int i=0; i<nums.size(); ++i) {
            int no = target - nums[i];
            if(mymap.find(no) != mymap.end()) {
                //found the element
                ans.push_back(i);
                ans.push_back(mymap[no]);
                return ans;
            }
            else {
                //Element not found
                mymap.insert(make_pair(nums[i], i));
            }
        }
        
        return ans;
    }
};