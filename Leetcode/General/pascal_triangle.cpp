Problem link: https://leetcode.com/problems/pascals-triangle/
Pascal Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector <int>> triangle;
        
        for (int row_no=0; row_no < numRows; row_no++) {
            vector<int> row(row_no+1, 1);
            
            for (int i=1; i<row.size()-1; i++) {
                row[i] = triangle[row_no-1][i-1] + triangle[row_no-1][i];
            }
            triangle.push_back(row);
        }
        return triangle;
        
    }
};