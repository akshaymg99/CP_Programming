/*
Problem link: https://leetcode.com/problems/group-anagrams/
Grouping anagram strings
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string>> anagrams;
        if (strs.size() == 0) return anagrams;
        unordered_map <string, vector<string>> table;
        for (string& s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            table[t].push_back(s);
        }
        
        for (auto& m: table) {
            anagrams.push_back(m.second);
        }
        
        return anagrams;
        
    }
};