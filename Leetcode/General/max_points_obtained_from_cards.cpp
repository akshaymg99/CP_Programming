/*
Problem link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Maximum points drawn from cards 
*/

class Solution {
private:
    int sumit(vector<int>& cardPoints, int i, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int index=i; index< i+(n-k); ++index) {
            sum += cardPoints[index];
        }
        return sum;
    }
    
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();      
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if (k == n)
            return total;
        
        int sum, cur = 0;
        for (int i=0; i<n-k; ++i) {
            cur = sumit(cardPoints, i, k);
            //cur = accumulate(cardPoints.begin()+i, cardPoints.begin()+i+(n-k), 0);
            sum = max(sum, total-cur);
        }
        
        return sum;
        
    }
};