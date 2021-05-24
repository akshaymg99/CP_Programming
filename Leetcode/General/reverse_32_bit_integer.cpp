// Problem link: https://leetcode.com/problems/reverse-integer/
// Reverse 32 bit integer without storing 64-bit integers (long datatypes)

class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        
        if (x <= INT_MIN)
            return 0;
        
        if (x == 0)
            return 0;
        if (x < 0) {
            flag = -1;
            x = x * (-1);
        }

        unsigned int prev = 0, r = 0, no = 0;
        
        while(x) {
            r = x % 10;
            no = (no * 10) + r;
            if ((no-r) /10 != prev) 
                return 0;
            
            prev = no;
            x = x / 10;
            
        }
        if (no > INT_MAX)
            return 0;
        
        return (no * flag);
    }
};