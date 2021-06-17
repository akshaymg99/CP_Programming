/*
Problem link: https://leetcode.com/problems/happy-number
Finding if given no is happy no (Repeat Sum of individual digit squares is 1)
*/

// Using Hashset to check if no is being repeated

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

// Using Flyod Cycle detection algorithm

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
        int slow_runner = n;
        int fast_runner = getnext(n);
        
        while (fast_runner != 1 && slow_runner != fast_runner) {
            slow_runner = getnext(slow_runner);
            fast_runner = getnext(getnext(fast_runner));
        }
        
        return fast_runner == 1;
    
    }
};