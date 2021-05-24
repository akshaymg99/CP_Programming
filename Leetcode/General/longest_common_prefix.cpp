/*
Problem link: https://leetcode.com/problems/longest-common-prefix/
Find common prefix among all the strings provided
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        char c;
        if (strs.size() == 0) 
            return res;
        if (strs.size() == 1)
            return strs[0];
        
        for (int i=0; i<strs[0].size(); ++i) {
            c = strs[0][i];
            for (auto s: strs) {
                if(i+1 > s.size() || c!=s[i])
                    return res;
            }
            res.push_back(c);
        }
        return res;
        
    }
};