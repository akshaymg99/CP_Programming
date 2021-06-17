/*
Problem link: https://leetcode.com/problems/happy-number
Finding if given no is happy no (Repeat Sum of individual digit squares is 1)
*/

class Solution {
public:
    int getnext (int n) {
        int sum = 0, r;
        while (n > 0) { 
            r = n % 10;
            sum += pow(r, 2);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set <int> mySet;
        while (n!=1 && mySet.find(n) == mySet.end()) {
            mySet.insert(n);
            n = getnext(n);
        }
    
        
        return n == 1;
    
    }
};