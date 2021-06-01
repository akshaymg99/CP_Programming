Problem link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
Max Area of Island (Can be done by DFS also)

class Solution {
public:
    int explore(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[i].size()) 
            return 0;
        
        if (!grid[i][j]) 
            return 0;
        
        grid[i][j] = 0;
        return 1 + explore(grid, i, j-1) + explore(grid, i-1, j) + explore(grid, i, j+1) + explore(grid, i+1, j);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                
                if (grid[i][j])
                    max_area = max(max_area, explore(grid, i, j));
            }
        }
        
        return max_area;
    }
};