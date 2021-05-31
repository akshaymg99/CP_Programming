Problem Link: https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1148/
Increment the integer represented by array elements

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
                
        
        reverse(digits.begin(), digits.end());
        int carry = 1, size = digits.size();
        for (int i=0; i<size; ++i) {
            
            if (carry) {
                
                if (digits[i] != 9) {
                    digits[i] ++;
                    carry = 0;
                }
                else if (digits[i] == 9) {
                    carry = 1;
                    digits[i] = 0;
                    
                    if (i == digits.size()-1)
                        digits.push_back(1);
                    
                }
                
            }
            
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};