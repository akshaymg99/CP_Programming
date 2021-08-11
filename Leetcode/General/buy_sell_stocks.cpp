/*
Buy and sell stocks (I)
Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ele = INT_MAX;
        int profit = 0;
        
        for (int i=0; i<prices.size(); ++i) {
            min_ele = min(prices[i], min_ele);
            
            profit = max(profit, prices[i]-min_ele);
        }
        return profit;
        
    }
};