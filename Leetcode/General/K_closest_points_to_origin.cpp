/*
Problem link: https://leetcode.com/problems/k-closest-points-to-origin/
K closest points to origin 
*/

// By using partial sort with custom function

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        partial_sort(points.begin(), points.begin()+k, points.end(), [](vector<int>&p, vector<int>&q) {return (p[0]*p[0] + p[1]*p[1]) < (q[0]*q[0] + q[1]*q[1]);});
        vector <vector<int>> ans(points.begin(), points.begin()+k);
        return ans;
    }
};