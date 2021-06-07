Problem link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/	
Minimum cost climbing stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};