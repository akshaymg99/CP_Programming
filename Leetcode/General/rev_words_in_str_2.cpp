/*
Problem link: https://leetcode.com/problems/reverse-words-in-a-string-ii/
Reverse words in a string 2
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        
        for (int start = 0; start<s.size(); start++) {
            if (s[start] != ' ') {
                
                int end  = start;
                while (end < n && s[end] != ' ') 
                    end ++;
                
                reverse(s.begin() + start, s.begin() + end);
                start = end;
                
            }
        }
        
        
    }
};