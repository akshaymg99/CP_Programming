Problem link: https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/ 
Spiral traversal matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return matrix[0];
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> seen(R, vector<int> (C, 0));
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        vector<int> ans;
        int cr=0, cc=0;
        
        for (int i=0; i<R*C; ++i) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = 1;
            cr = r + dr[di];
            cc = c + dc[di];
            
            if ( cr>=0 && cr<R  && cc>=0 && cc<C && seen[cr][cc]==0) {
                r = cr;
                c = cc;
            }
            else {
                di = (di + 1) % 4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        
        return ans;
        
    }
};