/*
Problem link: https://leetcode.com/problems/generate-parentheses/
Generate parenthesis
*/

// By Backtracking

class Solution {
private:
    vector<string> res;
    void generate(int open, int close, string st) {
        if (open == 0 && close == 0)
            res.push_back(st);
        
        if (open > 0)
            generate(open-1, close+1, st + '(');
        if (close > 0)
            generate(open, close-1, st + ')');
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
        generate(n, 0, "");
        return res;
    }
};