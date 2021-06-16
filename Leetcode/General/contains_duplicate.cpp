/*
Problem link: https://leetcode.com/problems/contains-duplicate 
Check if duplicates exist in given array/vector
*/

// Approach 1 (Using Hash set)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> set;
       
        for (int x: nums) {
            if (set.find(x) != set.end()) 
                return true;
            set.insert(x);
        }
        return false;
        
    }
};


// Approach 2 (Using Hash map)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (auto& num: nums) {
            if (map.find(num) != map.end())
                return true;
            map[num] = true;
            // map(make_pair(num, true));
        }
        return false;
    }
};

// Approach 3 (Comparing size of given vector and built set)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size_of_set = set<int> (nums.begin(), nums.end()).size();
        int size_of_nums = nums.size();
        
        return size_of_nums > size_of_set;
    }
};