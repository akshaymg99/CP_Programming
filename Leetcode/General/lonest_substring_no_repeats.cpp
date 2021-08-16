/*
Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters 
Longest substring without repeating
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size())
            return 0;
        
        int left = 0, right = 0;
        unordered_map<char, int> hmap;
        int res = INT_MIN;
        
        while (right < s.size()) {
            char c = s.at(right);
            hmap[c]++;
            
            while (hmap[c] > 1) {
                char l = s.at(left);
                hmap[l]--;
                left++;  
            }
                
            res = max(res, right-left+1); 
            right++;
        }
        
        return res;
    }
};