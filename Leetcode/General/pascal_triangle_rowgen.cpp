/*
Problem link: https://leetcode.com/problems/pascals-triangle-ii/
Pascal's traingle row generatiom
*/

// Using Dynamic programming memoization

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = vector<int> (rowIndex + 1, 1);
        
        for (int i=1; i<rowIndex; ++i) {
            for (int j=i; j>0; j--)
                ans[j] = ans[j] + ans[j-1];
        }
        
        return ans;
    }
};

// Using combinatorics

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans {1};
        
        for (int i=1; i<=rowIndex; ++i) {
            ans.push_back( (long int)ans.back() * (long long)(rowIndex - i + 1)/i );
        }
        return ans;
    }
};