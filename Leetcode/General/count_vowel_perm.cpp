/*
Problem link: https://leetcode.com/problems/count-vowels-permutation/
Counting vowel permuations as per given rules
0..4 represent a,e,i,o,u respectively. Rules are summarised using integers:

0 (a)       =>  1
1 (e)       =>  0 / 2
2 (i)       =>  0 / 1 / 3 / 4
3 (o)       =>  2 / 4
4 (u)       =>  0

dp[k][i] will denote the number of possible strings of length i that end at vowel numbered k.
We are using stored number of strings possible for length i-1 to calculate for length i.
We will use only those state for dp[k] from which it is allowed to use kth vowel at next position.
*/


class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        long dp[5][n+1];
        long ans = 0;
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
        
        for (int i=2; i<=n; ++i) {
            dp[0][i] = dp[1][i-1];
            dp[1][i] = ( dp[0][i-1] + dp[2][i-1] ) % MOD; 
            dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1] ) % MOD;
            dp[3][i] = (dp[2][i-1] + dp[4][i-1] ) % MOD;
            dp[4][i] = dp[0][i-1];
        }
        
        for (int i=0; i<5; ++i) {
            ans = (ans + dp[i][n] ) % MOD;
        }
        return ans;
        
    }
};