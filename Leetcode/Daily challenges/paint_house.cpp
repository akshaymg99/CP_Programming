Problem link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3763/
Paint house problem

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        int size = costs.size();
        if (!size)
            return 0;
        
        for (int i=1; i<size; ++i) {
            costs[i][0] += min(costs[i-1][1] , costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0] , costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0] , costs[i-1][1]);
        }
        
        return min(min(costs[size-1][0], costs[size-1][1]), costs[size-1][2]);
    }
};