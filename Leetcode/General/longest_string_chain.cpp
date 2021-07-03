/*
Problem link: https://leetcode.com/problems/longest-string-chain/
Longest string chain
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.size() < s2.size();
        });
        unordered_map<string, int> dp;
        int longest_seq = 1;
        
        for (string &word: words) {
            int present_len = 1;
            for (int i=0; i<word.size(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i+1, word.length()-i-1 );
                if (dp.find(predecessor) != dp.end()) {
                    int prev_len = dp[predecessor];
                    present_len = max(present_len, prev_len+1);
                }
            }   
            dp[word] = present_len;
            longest_seq = max(longest_seq, present_len);
            
        }
        return longest_seq;        
    }
};