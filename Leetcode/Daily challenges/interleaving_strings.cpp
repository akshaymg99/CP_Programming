/*
Problem link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3765/
Interleaving strings
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s3.length() != s1.length() + s2.length()) 
            return false;

        vector<vector<bool>> dp(s1.length()+1, vector<bool> (s2.length()+1, false));
        
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2.at(j - 1) == s3.at(i + j - 1);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1.at(i - 1) == s3.at(i + j - 1);
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1.at(i - 1) == s3.at(i + j - 1)) || (dp[i][j - 1] &&                                 s2.at(j - 1) == s3.at(i + j - 1));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }

        
};