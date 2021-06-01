Problem link: https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/
Add binary numbers represented in string

class Solution {
public:
    string addBinary(string a, string b) {
        int len_1 = a.length(), len_2 = b.length();
        
        for (int i=0; i<len_1/2; ++i)
            swap(a[i], a[len_1 -i -1]);
        
        for (int i=0; i<len_2/2; ++i) 
            swap(b[i], b[len_2 -i -1]);
        
        if (len_1 > len_2) {
             while (len_2 != len_1) {
                b += '0';
                len_2 ++;
            }   
        }
        else if (len_2 > len_1) {
            while (len_1 != len_2) {
                a += '0';
                len_1 ++;
            }
        }
                 
        int carry = 0;
        string ans = "";
    
        for (int i = 0; i<a.size(); i++) {
            if (carry) {
                if (a[i] == '1' && b[i] == '1') {
                    carry = 1;
                    ans.push_back('1');
                }
                else if (a[i] == '1' && b[i] == '0') {
                    carry = 1;
                    ans.push_back('0');
                }
                else if (a[i] == '0' && b[i] == '1') {
                    carry = 1;
                    ans.push_back('0');
                }
                else if (a[i] == '0' && b[i] == '0') {
                    carry = 0;
                    ans.push_back('1');
                }
            }
            else {
                if (a[i] == '1' && b[i] == '1') {
                    carry = 1;
                    ans.push_back('0');
                }
                else if (a[i] == '1' && b[i] == '0') {
                    carry = 0;
                    ans.push_back('1');
                }
                else if (a[i] == '0' && b[i] == '1') {
                    carry = 0;
                    ans.push_back('1');
                }
                else if (a[i] == '0' && b[i] == '0') {
                    carry = 0;
                    ans.push_back('0');
                }
                
            }
            
        }
        if (carry) 
            ans.push_back('1');
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};